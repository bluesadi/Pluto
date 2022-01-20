#ifndef LLVM_FLATTENING_H
#define LLVM_FLATTENING_H

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"

namespace llvm{
    class Flattening : public FunctionPass{
        public:
            static char ID;
            bool enable;

            Flattening(bool enable) : FunctionPass(ID){
                this->enable = enable;
            }

            void flatten(Function &F);
    
            bool runOnFunction(Function &F);
    };

    FunctionPass* createFlatteningPass(bool enable);
}

#endif // LLVM_FLATTENING_H