#pragma once

#include "llvm/Passes/PassBuilder.h"

using namespace llvm;

namespace Pluto {

struct IndirectCalls : PassInfoMixin<IndirectCalls> {
    PreservedAnalyses run(Module &M, ModuleAnalysisManager &AM);

    static bool isRequired() { return true; }
};

}; // namespace Pluto