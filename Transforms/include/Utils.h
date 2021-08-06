#ifndef __UTILS_H__
#define __UTILS_H__

#include "llvm/IR/Function.h"
#define INIT_CONTEXT(F) CONTEXT=&F.getContext()
#define TYPE_I32 Type::getInt32Ty(*CONTEXT)
#define CONST_I32(V) ConstantInt::get(TYPE_I32, V, false)
#define CONST(T, V) ConstantInt::get(T, V)

extern llvm::LLVMContext *CONTEXT;

namespace llvm{
    void fixStack(Function &F);
    BasicBlock* createCloneBasicBlock(BasicBlock *BB);
}

#endif