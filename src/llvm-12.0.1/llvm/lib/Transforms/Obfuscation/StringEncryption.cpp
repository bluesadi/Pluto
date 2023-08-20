#include "llvm/Transforms/Obfuscation/StringEncryption.h"

#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Transforms/Utils/LowerSwitch.h"
#include <vector>

namespace Pluto {

PreservedAnalyses StringEncryption::run(Module &M, ModuleAnalysisManager &AM) {
    std::vector<GlobalVariable *> GVs;
    for (auto &GV : M.getGlobalList()) {
        GVs.push_back(&GV);
    }
    for (auto &GV : GVs) {
        if (GV->hasInitializer() && GV->getInitializer() && GV->getName().contains(".str") &&
            !GV->getSection().equals("llvm.metadata")) {
            ConstantDataArray *dataArray = dyn_cast<ConstantDataArray>(GV->getInitializer());
            if (dataArray) {
                uint64_t eleBytes = dataArray->getElementByteSize();
                uint64_t eleNum = dataArray->getNumElements();
                const char *data = dataArray->getRawDataValues().data();
                if (data) {
                    // errs() << data << GV->use_begin << "\n";
                }
            }
        }
    }
    return PreservedAnalyses::all();
}

}; // namespace Pluto