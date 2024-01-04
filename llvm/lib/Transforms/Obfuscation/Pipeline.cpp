#pragma once

#include "llvm/IR/PassManager.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Transforms/Obfuscation/BogusControlFlow.h"
#include "llvm/Transforms/Obfuscation/Flattening.h"
#include "llvm/Transforms/Obfuscation/GlobalEncryption.h"
#include "llvm/Transforms/Obfuscation/HelloWorld.h"
#include "llvm/Transforms/Obfuscation/IndirectCall.h"
#include "llvm/Transforms/Obfuscation/MBAObfuscation.h"
#include "llvm/Transforms/Obfuscation/Substitution.h"
#include "llvm/Transforms/Utils/LowerSwitch.h"

using namespace llvm;
using namespace Pluto;

static cl::list<std::string> Passes("passes", cl::CommaSeparated, cl::Hidden, cl::desc("Obfuscation passes"));

struct LowerSwitchWrapper : LowerSwitchPass {
    static bool isRequired() { return true; }
};

ModulePassManager buildObfuscationPipeline() {
    ModulePassManager MPM;
    FunctionPassManager FPM;
    for (auto pass : Passes) {
        if (pass == "hlw") {
            FPM.addPass(HelloWorld());
        } else if (pass == "idc") {
            MPM.addPass(IndirectCall());
        } else if (pass == "fla") {
            FPM.addPass(LowerSwitchWrapper());
            FPM.addPass(Flattening());
        } else if (pass == "sub") {
            FPM.addPass(Substitution());
        } else if (pass == "mba") {
            FPM.addPass(MbaObfuscation());
        } else if (pass == "bcf") {
            FPM.addPass(BogusControlFlow());
        } else if (pass == "gle") {
            MPM.addPass(GlobalEncryption());
        }
    }
    MPM.addPass(createModuleToFunctionPassAdaptor(std::move(FPM)));
    return MPM;
}

ModulePassManager buildLTOObfuscationPipeline() {
    ModulePassManager MPM;
    FunctionPassManager FPM;
    for (auto pass : Passes) {
        if (pass == "hlw") {
            FPM.addPass(HelloWorld());
        } else if (pass == "idc") {
            MPM.addPass(IndirectCall());
        } else if (pass == "gle") {
            MPM.addPass(GlobalEncryption());
        }
    }
    MPM.addPass(createModuleToFunctionPassAdaptor(std::move(FPM)));
    return MPM;
}