#ifndef LLVM_UTILS_H
#define LLVM_UTILS_H

#include "llvm/IR/Function.h"
#include "llvm/IR/Instruction.h"
#include "llvm/Support/CommandLine.h"

#define INIT_CONTEXT(X) CONTEXT = &X.getContext()
#define TYPE_I64 Type::getInt64Ty(*CONTEXT)
#define TYPE_I32 Type::getInt32Ty(*CONTEXT)
#define TYPE_I8 Type::getInt8Ty(*CONTEXT)
#define GET_TYPE(X) TYPE::getInt(X) Ty(*CONTEXT)
#define CONST_I64(V) ConstantInt::get(TYPE_I64, V, false)
#define CONST_I32(V) ConstantInt::get(TYPE_I32, V, false)
#define CONST_I8(V) ConstantInt::get(TYPE_I8, V, false)
#define CONST(T, V) ConstantInt::get(T, V)
#define RANDOM(X) (cryptoutils->get_uint8_t() % 100 < X)

#define TAG_INCLUDE "include"
#define TAG_EXCLUDE "exclude"
#define FUNC_INCLUDE __attribute__((annotate(TAG_INCLUDE)))
#define FUNC_EXCLUDE __attribute__((annotate(TAG_EXCLUDE)))

#define SKIP_IF_SHOULD(F)                                                        \
    auto __anno__ = readAnnotation(&F);                                          \
    if (FilterMode == FilterModeEnum::INCLUDE &&                                 \
        __anno__.find(TAG_INCLUDE) == std::string::npos) {                       \
        return false;                                                            \
    }                                                                            \
    if (FilterMode == FilterModeEnum::EXCLUDE &&                                 \
        __anno__.find(TAG_EXCLUDE) != std::string::npos) {                       \
        return false;                                                            \
    }
enum FilterModeEnum { NONE, INCLUDE, EXCLUDE };

extern llvm::cl::opt<FilterModeEnum> FilterMode;
extern llvm::LLVMContext *CONTEXT;

namespace llvm {
void fixStack(Function &F);
BasicBlock *createCloneBasicBlock(BasicBlock *BB);
std::string readAnnotation(Function *f);

// Check whether the instruction is a CXX Exceptions Instruction
bool is_exceptional_instruction(llvm::Instruction &I);
} // namespace llvm

#endif // LLVM_UTILS_H
