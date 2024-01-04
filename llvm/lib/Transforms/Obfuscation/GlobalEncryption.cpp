#include "llvm/Transforms/Obfuscation/GlobalEncryption.h"

#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/FormatVariadic.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include "llvm/Transforms/Utils/LowerSwitch.h"
#include "llvm/Transforms/Utils/ModuleUtils.h"
#include <vector>

namespace Pluto {

bool shouldSkip(GlobalVariable &GV) {
    // Do not encrypt LLVM-generated GV like llvm.global_ctors
    if (GV.getName().startswith("llvm.")) {
        return true;
    }
    // Only encrypt GV with internal or private linkage
    // Other linkages may cause problem. For example, if a GV has LinkOnce linkage, two global variables in two modules
    // with the same name will be merged into one GV at link-time and the merged GV will be decrypted twice (the two
    // decrypt functions are not merged).
    // Reference: https://llvm.org/docs/LangRef.html#linkage-types
    if (!GV.hasInternalLinkage() && !GV.hasPrivateLinkage()) {
        return true;
    }
    // Encrypt the GV only if it's an integer or integer array
    if (!GV.getValueType()->isIntegerTy() &&
        (!GV.getValueType()->isArrayTy() || !cast<ArrayType>(GV.getValueType())->getElementType()->isIntegerTy())) {
        return true;
    }
    // Make sure the GV has an initializer
    if (!GV.hasInitializer() || !GV.getInitializer()) {
        return true;
    }
    // Make sure the GV doesn't belong to any custom section (which means it belongs .data section by default)
    // We conservatively skip data in custom section to avoid unexpected behaviors after obfuscation
    if (GV.hasSection()) {
        return true;
    }
    return false;
}

PreservedAnalyses GlobalEncryption::run(Module &M, ModuleAnalysisManager &AM) {
    std::vector<GlobalVariable *> GVs;
    for (auto &GV : M.getGlobalList()) {
        if (!shouldSkip(GV)) {
            GVs.push_back(&GV);
        }
    }
    for (auto &GV : GVs) {
        if (ConstantDataArray *dataArray = dyn_cast<ConstantDataArray>(GV->getInitializer())) {
            uint64_t eleByteSize = dataArray->getElementByteSize();
            uint64_t eleNum = dataArray->getNumElements();
            const char *data = dataArray->getRawDataValues().data();
            uint64_t dataSize = eleByteSize * eleNum;
            if (data && eleByteSize <= 8) {
                char *dataCopy = new char[dataSize];
                memcpy(dataCopy, data, dataSize);
                uint64_t key = cryptoutils->get_uint64_t();
                // A simple xor encryption
                for (uint32_t i = 0; i < dataSize; i++) {
                    dataCopy[i] ^= ((char *)&key)[i % eleByteSize];
                }
                GV->setInitializer(
                    ConstantDataArray::getRaw(StringRef(dataCopy, dataSize), eleNum, dataArray->getElementType()));
                GV->setConstant(false);
                insertArrayDecryption(M, GV, key, eleNum);
            }
        } else if (ConstantInt *dataInt = dyn_cast<ConstantInt>(GV->getInitializer())) {
            uint64_t key = cryptoutils->get_uint64_t();
            ConstantInt *enc = ConstantInt::get(dataInt->getType(), key ^ dataInt->getZExtValue());
            GV->setInitializer(enc);
            GV->setConstant(false);
            insertIntDecryption(M, GV, key);
        }
    }
    return PreservedAnalyses::all();
}

void GlobalEncryption::insertArrayDecryption(Module &M, GlobalVariable *GV, uint64_t key, uint64_t eleNum) {
    static uint64_t cnt = 0;
    LLVMContext &context = M.getContext();
    FunctionType *funcType = FunctionType::get(Type::getVoidTy(context), false);
    std::string funcName = formatv("decrypt.arr.{0:d}", cnt++);
    FunctionCallee callee = M.getOrInsertFunction(funcName, funcType);
    Function *func = cast<Function>(callee.getCallee());
    func->setLinkage(GlobalValue::LinkageTypes::PrivateLinkage);
    BasicBlock *head = BasicBlock::Create(context, "head", func);
    BasicBlock *forCond = BasicBlock::Create(context, "for.cond", func);
    BasicBlock *forBody = BasicBlock::Create(context, "for.body", func);
    BasicBlock *forInc = BasicBlock::Create(context, "for.inc", func);
    BasicBlock *forEnd = BasicBlock::Create(context, "for.inc", func);

    IRBuilder<> builder(context);

    builder.SetInsertPoint(head);
    AllocaInst *indexPtr = builder.CreateAlloca(Type::getInt32Ty(context));
    builder.CreateStore(ConstantInt::get(Type::getInt32Ty(context), 0), indexPtr);
    builder.CreateBr(forCond);

    builder.SetInsertPoint(forCond);
    LoadInst *index = builder.CreateLoad(Type::getInt32Ty(context), indexPtr);
    Value *cond = builder.CreateICmpSLT(index, ConstantInt::get(Type::getInt32Ty(context), eleNum));
    builder.CreateCondBr(cond, forBody, forEnd);

    builder.SetInsertPoint(forBody);

    Value *elePtr = builder.CreateGEP(GV->getValueType(), GV, {ConstantInt::get(Type::getInt32Ty(context), 0), index});
    Type *eleType = cast<ArrayType>(GV->getValueType())->getElementType();
    builder.CreateStore(builder.CreateXor(builder.CreateLoad(eleType, elePtr), ConstantInt::get(eleType, key)), elePtr);
    builder.CreateBr(forInc);

    builder.SetInsertPoint(forInc);
    builder.CreateStore(builder.CreateAdd(index, ConstantInt::get(Type::getInt32Ty(context), 1)), indexPtr);
    builder.CreateBr(forCond);

    builder.SetInsertPoint(forEnd);
    builder.CreateRetVoid();

    appendToGlobalCtors(M, func, 0);
}

void GlobalEncryption::insertIntDecryption(Module &M, GlobalVariable *GV, uint64_t key) {
    static uint64_t cnt = 0;
    LLVMContext &context = M.getContext();
    FunctionType *funcType = FunctionType::get(Type::getVoidTy(context), false);
    std::string funcName = formatv("decrypt.int.{0:d}", cnt++);
    FunctionCallee callee = M.getOrInsertFunction(funcName, funcType);
    Function *func = cast<Function>(callee.getCallee());
    func->setLinkage(GlobalValue::LinkageTypes::PrivateLinkage);

    BasicBlock *BB = BasicBlock::Create(context, "BB", func);

    IRBuilder<> builder(context);
    builder.SetInsertPoint(BB);
    LoadInst *val = builder.CreateLoad(GV->getValueType(), GV);
    builder.CreateStore(builder.CreateXor(val, ConstantInt::get(GV->getValueType(), key)), GV);
    builder.CreateRetVoid();

    appendToGlobalCtors(M, func, 0);
}
}; // namespace Pluto