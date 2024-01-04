#pragma once

#include "llvm/Passes/PassBuilder.h"

using namespace llvm;

namespace Pluto {

struct BogusControlFlow : PassInfoMixin<BogusControlFlow> {
    PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);

    static bool isRequired() { return true; }
};

}; // namespace Pluto