#include "llvm/Transforms/Obfuscation/TrapAngr.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Transforms/Obfuscation/Utils.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include <vector>
#include <string>
#include "llvm/Support/FormatVariadic.h"
#include "llvm/Transforms/Obfuscation/VariableSubstitution.h"
using namespace llvm;
using std::vector;
using std::string;

static cl::opt<int> ObfuTimes("trap-angr-times", cl::init(1), cl::desc("Run the TrapAngr pass <trap-angr-times> time(s)"));
static cl::opt<int> ObfuProb("trap-angr-prob", cl::init(40), cl::desc("Each constant will be substituted with a probability of <trap-angr-prob>%"));

/*
uint32_t remu3(uint32_t n){
    return n - 3 * ((n * (uint64_t)0xAAAAAAAB) >> 33);
}
*/
Value* insertFastRem3(Value *n, BasicBlock *insertAfter){
    IRBuilder<> builder(*CONTEXT);
    builder.SetInsertPoint(insertAfter);
    Value *op1, *op2, *op3, *op4, *op5, *op6;
    op1 = builder.CreateZExt(n, TYPE_I64);
    op2 = builder.CreateMul(CONST_I64(0xAAAAAAAB), op1);
    op3 = builder.CreateLShr(op2, 33);
    op4 = builder.CreateTrunc(op3, TYPE_I32);
    op5 = builder.CreateMul(op4, CONST_I32(3));
    op6 = builder.CreateSub(n, op5);
    return op6;
}

Value* genRandIndex(Instruction *I){
    Module &M = *I->getModule();
    string funcName = formatv("genrand.{0:x-}", cryptoutils->get_uint64_t());
    Function* genFunc = cast<Function>(M.getOrInsertFunction(funcName, FunctionType::getInt32Ty(*CONTEXT)).getCallee());
    BasicBlock *entry = BasicBlock::Create(*CONTEXT, "entry", genFunc);
    IRBuilder<> builder(*CONTEXT);
    builder.SetInsertPoint(entry);
    Function *randFunc = cast<Function>(M.getOrInsertFunction("rand", FunctionType::getInt32Ty(*CONTEXT)).getCallee());
    randFunc->setDSOLocal(true);
    Value *op1, *op2;
    op1 = builder.CreateCall(randFunc->getFunctionType(), randFunc);
    op2 = insertFastRem3(op1, entry);
    builder.CreateRet(op2);
    FunctionPass *substitutionPass = createVariableSubstitutionPass(true);
    substitutionPass->runOnFunction(*genFunc);
    builder.SetInsertPoint(I);
    return builder.CreateCall(genFunc->getFunctionType(), genFunc);
}

void TrapAngr::substitute(Instruction *I, int i){
    Module &M = *I->getModule();
    ConstantInt *val = cast<ConstantInt>(I->getOperand(i));
    IntegerType *eleType = val->getType();
    ArrayType *arrayType = ArrayType::get(eleType, 3);
    GlobalVariable *valTriple = new GlobalVariable(
        M, 
        arrayType, 
        true, 
        GlobalValue::PrivateLinkage, 
        (ConstantArray*)ConstantArray::get(arrayType, {val, val, val})
    );
    Value *randIndex = genRandIndex(I);
    IRBuilder<> builder(*CONTEXT);
    builder.SetInsertPoint(I);
    Value *anyElePtr = builder.CreateGEP(valTriple, {CONST_I32(0), randIndex});
    LoadInst *anyEle = builder.CreateLoad(eleType, anyElePtr);
    I->setOperand(i, anyEle);
}

bool TrapAngr::runOnFunction(Function &F){
    INIT_CONTEXT(F);
    if(enable && !F.getName().startswith("genrand.")){
        for(int i = 0;i < ObfuTimes;i ++){
            for(BasicBlock &BB : F){
                vector<Instruction*> origInst;
                for(Instruction &I : BB){
                    origInst.push_back(&I);
                }
                for(Instruction *I : origInst){
                    if(isa<StoreInst>(I) || isa<CmpInst>(I) || isa<BinaryOperator>(I)){
                        int operandNum = I->getNumOperands();
                        for(int i = 0;i < operandNum;i ++){
                            if(isa<ConstantInt>(I->getOperand(i)) 
                                && cryptoutils->get_uint8_t() % 100 < ObfuProb){
                                substitute(I, i);
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
    return false;
}

FunctionPass* llvm::createTrapAngrPass(bool enable){
    return new TrapAngr(enable);
}

char TrapAngr::ID = 0;