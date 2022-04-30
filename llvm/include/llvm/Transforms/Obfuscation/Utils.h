#ifndef LLVM_UTILS_H
#define LLVM_UTILS_H

#include "llvm/IR/Function.h"
#define INIT_CONTEXT(X) CONTEXT=&X.getContext()
#define TYPE_I64 Type::getInt64Ty(*CONTEXT)
#define TYPE_I32 Type::getInt32Ty(*CONTEXT)
#define TYPE_I8 Type::getInt8Ty(*CONTEXT)
#define GET_TYPE(X) TYPE::getInt(X)Ty(*CONTEXT)
#define CONST_I64(V) ConstantInt::get(TYPE_I64, V, false)
#define CONST_I32(V) ConstantInt::get(TYPE_I32, V, false)
#define CONST_I8(V) ConstantInt::get(TYPE_I8, V, false)
#define CONST(T, V) ConstantInt::get(T, V)
#define RANDOM(X) (cryptoutils->get_uint8_t() % 100 < X)

extern llvm::LLVMContext *CONTEXT;

namespace llvm{
    void fixStack(Function &F);
    BasicBlock* createCloneBasicBlock(BasicBlock *BB);
    std::string readAnnotate(Function *f);
}

#endif // LLVM_UTILS_H
