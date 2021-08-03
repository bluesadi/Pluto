#include "llvm/IR/Function.h"
#include "llvm/Pass.h"

namespace llvm{
    FunctionPass* createSplitBasicBlockPass();
}