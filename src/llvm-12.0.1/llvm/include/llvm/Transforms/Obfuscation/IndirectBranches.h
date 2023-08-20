#pragma once

#include "llvm/Passes/PassBuilder.h"

using namespace llvm;

namespace Pluto {

struct IndirectBranches : PassInfoMixin<IndirectBranches> {
    PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);

    static bool isRequired() { return true; }
};

}; // namespace Pluto