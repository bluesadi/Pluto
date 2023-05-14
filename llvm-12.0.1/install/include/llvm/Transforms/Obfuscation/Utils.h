#pragma once
#include "llvm/IR/Function.h"

using namespace llvm;

namespace Utils {
void fixStack(Function &F);
}