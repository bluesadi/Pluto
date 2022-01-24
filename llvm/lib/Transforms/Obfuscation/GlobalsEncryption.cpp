#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/CommandLine.h"
#include <sstream>
#include <vector>
#include "llvm/Transforms/Obfuscation/Utils.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include "llvm/Transforms/Utils/ModuleUtils.h"
#include "llvm/Transforms/Obfuscation/GlobalsEncryption.h"
#include "llvm/Support/FormatVariadic.h"

using namespace std;
using namespace llvm;

static cl::opt<int> ObfuTimes("gle-times", cl::init(1), cl::desc("Run GlobalsEncryption pass <gle-times> time(s)"));
static cl::opt<bool> OnlyStr("onlystr", cl::init(false), cl::desc("Encrypt string variable only"));

bool GlobalsEncryption::runOnModule(Module &M){
    if(!enable){
        return false;
    }
    INIT_CONTEXT(M);
    for(int i = 0;i < ObfuTimes;i ++){
        vector<GlobalVariable*> GVs;
        for(GlobalVariable &GV : M.getGlobalList()){
            GVs.push_back(&GV);
        }
        for(GlobalVariable *GV : GVs){
            if(GV->hasInitializer() && (GV->getName().contains(".str") || !OnlyStr)
                // Do not encrypt globals having a section specified as "llvm.metadata"
                && !GV->getSection().equals("llvm.metadata")){
                Constant *initializer = GV->getInitializer();
                ConstantInt *varData = dyn_cast<ConstantInt>(initializer);
                ConstantDataSequential *seqData = dyn_cast<ConstantDataSequential>(initializer);
                if(seqData && GV->getValueType()->isArrayTy()){
                    char *data = const_cast<char*>(seqData->getRawDataValues().data());
                    uint32_t size = seqData->getElementByteSize();
                    uint32_t len = seqData->getNumElements();
                    uint64_t key = cryptoutils->get_uint64_t();
                    // A simple xor encryption
                    for(int i = 0;i < len * size;i ++){
                        data[i] ^= ((char*)&key)[i % size];
                    }
                    GV->setConstant(false);
                    insertArrayDecryption(M, {GV, key, len});
                }else if(varData && GV->getValueType()->isIntegerTy()){
                    uint64_t key = cryptoutils->get_uint64_t();
                    ConstantInt *enc = CONST(varData->getType(), key ^ varData->getZExtValue());
                    GV->setConstant(false);
                    insertIntDecryption(M, {GV, key, 1LL});
                }
            }
        }
    }
    return true;
}

void GlobalsEncryption::insertIntDecryption(Module &M, EncryptedGV encGV){
    vector<Type*>args;
    FunctionType* funcType = FunctionType::get(Type::getVoidTy(M.getContext()), args, false);
    string funcName = formatv("{0}.{1}.decrypt", encGV.GV->getName(), cryptoutils->get_uint64_t());
    FunctionCallee callee = M.getOrInsertFunction(funcName, funcType);
    Function *func = cast<Function>(callee.getCallee());

    BasicBlock *entry = BasicBlock::Create(*CONTEXT, "entry", func);
    IRBuilder<> builder(*CONTEXT);
    builder.SetInsertPoint(entry);
    LoadInst *val = builder.CreateLoad(encGV.GV);
    Value *xorVal = builder.CreateXor(val, CONST(encGV.GV->getValueType(), encGV.key));
    builder.CreateStore(xorVal, encGV.GV);
    builder.CreateRetVoid();
    appendToGlobalCtors(M, func, 0);
}

void GlobalsEncryption::insertArrayDecryption(Module &M, EncryptedGV encGV){
    vector<Type*>args;
    FunctionType* funcType = FunctionType::get(Type::getVoidTy(M.getContext()), args, false);
    string funcName = formatv("{0}.{1}.decrypt", encGV.GV->getName(), cryptoutils->get_uint64_t());
    FunctionCallee callee = M.getOrInsertFunction(funcName, funcType);
    Function *func = cast<Function>(callee.getCallee());
    BasicBlock *entry = BasicBlock::Create(*CONTEXT, "entry", func);
    BasicBlock *forCond = BasicBlock::Create(*CONTEXT, "for.cond", func);
    BasicBlock *forBody = BasicBlock::Create(*CONTEXT, "for.body", func);
    BasicBlock *forInc = BasicBlock::Create(*CONTEXT, "for.inc", func);
    BasicBlock *forEnd = BasicBlock::Create(*CONTEXT, "for.inc", func);

    IRBuilder<> builder(*CONTEXT);
    builder.SetInsertPoint(entry);
    AllocaInst *indexPtr = builder.CreateAlloca(TYPE_I32, CONST_I32(1), "i");
    builder.CreateStore(CONST_I32(0), indexPtr);
    builder.CreateBr(forCond);
    builder.SetInsertPoint(forCond);
    LoadInst *index = builder.CreateLoad(TYPE_I32, indexPtr);
    ICmpInst *cond = cast<ICmpInst>(builder.CreateICmpSLT(index, CONST_I32(encGV.len)));
    builder.CreateCondBr(cond, forBody, forEnd);
    builder.SetInsertPoint(forBody);
    Value *indexList[2] = {CONST_I32(0), index};
    Value *ele = builder.CreateGEP(encGV.GV, ArrayRef<Value*>(indexList, 2));
    ArrayType *arrTy = cast<ArrayType>(encGV.GV->getValueType());
    Type *eleTy = arrTy->getElementType();
    Value *encEle = builder.CreateXor(builder.CreateLoad(ele), CONST(eleTy, encGV.key));
    builder.CreateStore(encEle, ele);
    builder.CreateBr(forInc);
    builder.SetInsertPoint(forInc);
    builder.CreateStore(builder.CreateAdd(index, CONST_I32(1)), indexPtr);
    builder.CreateBr(forCond);

    builder.SetInsertPoint(forEnd);
    builder.CreateRetVoid();
    appendToGlobalCtors(M, func, 0);
}

ModulePass* llvm::createGlobalsEncryptionPass(bool enable){
    return new GlobalsEncryption(enable);
}

char GlobalsEncryption::ID = 0;