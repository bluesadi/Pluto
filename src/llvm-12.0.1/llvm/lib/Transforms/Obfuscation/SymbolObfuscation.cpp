#include "llvm/Transforms/Obfuscation/SymbolObfuscation.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FormatVariadic.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/YAMLParser.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include <fstream>
#include <string>

using namespace llvm;
using std::string;
using sys::fs::createUniqueFile;

static void rewriteComdat(Module &M, GlobalObject *GO, const std::string &Source,
                          const std::string &Target) {
    if (Comdat *CD = GO->getComdat()) {
        auto &Comdats = M.getComdatSymbolTable();

        Comdat *C = M.getOrInsertComdat(Target);
        C->setSelectionKind(CD->getSelectionKind());
        GO->setComdat(C);

        Comdats.erase(Comdats.find(Source));
    }
}

PreservedAnalyses Pluto::SymbolObfuscation::run(Module &M, ModuleAnalysisManager &AM) {
    for (Function &F : M.getFunctionList()) {
        string source = F.getName().data();
        if (source == "main" || F.empty())
            continue;
        string target = formatv("func{0:d}", cryptoutils->get_uint32_t());
        if (GlobalObject *GO = dyn_cast<GlobalObject>(&F)) {
            rewriteComdat(M, GO, source, target);
        }
        F.setName(target);
    }

    return PreservedAnalyses::none();
}