#pragma once

#include "llvm/Passes/PassBuilder.h"
#include "llvm/Transforms/Utils.h"
#include "llvm/Transforms/Utils/LowerSwitch.h"

using namespace llvm;

namespace Pluto {

struct Flattening : PassInfoMixin<Flattening> {
    PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);

    static bool isRequired() { return true; }
};

}; // namespace Pluto