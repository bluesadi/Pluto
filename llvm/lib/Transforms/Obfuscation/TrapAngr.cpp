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
using namespace llvm;
using std::vector;

static cl::opt<int> ObfuTimes("trap-angr-times", cl::init(1), cl::desc("Run TrapAngr pass <trap-angr-times> time(s)"));
static cl::opt<int> ObfuProb("trap-angr-prob", cl::init(100), cl::desc("A constant will be substituted with a probability of <trap-angr-prob>%"));

/*
uint32_t remu3(uint32_t n){
    return n - 3 * ((n * (uint64_t)0xAAAAAAAB) >> 33);
}
*/
Value* insertFastRem3(Value *n, Instruction *insertBefore){
    IRBuilder<> builder(*CONTEXT);
    builder.SetInsertPoint(insertBefore);
    Value *op1, *op2, *op3, *op4, *op5, *op6;
    op1 = builder.CreateZExt(n, TYPE_I64);
    op2 = builder.CreateMul(CONST_I64(0xAAAAAAAB), op1);
    op3 = builder.CreateLShr(op2, 33);
    op4 = builder.CreateTrunc(op3, TYPE_I32);
    op5 = builder.CreateMul(op4, CONST_I32(3));
    op6 = builder.CreateSub(n, op5);
    return op6;
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
    Function *randFunc = (Function*)M.getOrInsertFunction("rand", FunctionType::getInt32Ty(*CONTEXT)).getCallee();
    randFunc->setDSOLocal(true);
    IRBuilder<> builder(*CONTEXT);
    builder.SetInsertPoint(I);
    CallInst *rand = builder.CreateCall(randFunc->getFunctionType(), randFunc);
    Value *index = insertFastRem3(rand, I);
    Value *indexList[2] = {CONST_I32(0), index};
    Value *anyElePtr = builder.CreateGEP(valTriple, ArrayRef<Value*>(indexList, 2));
    LoadInst *anyEle = builder.CreateLoad(eleType, anyElePtr);
    I->setOperand(i, anyEle);
}

bool TrapAngr::runOnFunction(Function &F){
    INIT_CONTEXT(F);
    if(enable){
        for(int i = 0;i < ObfuTimes;i ++){
            for(BasicBlock &BB : F){
                vector<Instruction*> origInst;
                for(Instruction &I : BB){
                    origInst.push_back(&I);
                }
                for(Instruction *I : origInst){
                    if(isa<BinaryOperator>(I)){
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