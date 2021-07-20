#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

namespace{
    struct Substitution : public FunctionPass {
        static char ID;
        Substitution() : FunctionPass(ID) {}

        bool runOnFunction(Function &F) override {
            return true;
        }
    };
}

char Substitution::ID = 0;
static RegisterPass<Substitution> X("sub", "Substitution pass developed by 34r7hm4n.")