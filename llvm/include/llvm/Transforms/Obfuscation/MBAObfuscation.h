#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/IR/Instructions.h"

namespace llvm{

    class MBAObfuscation : public FunctionPass {
        public:
            static char ID;
            bool enable;

            MBAObfuscation(bool enable) : FunctionPass(ID) {
                this->enable = enable;
            }

            bool runOnFunction(Function &F);

            void substitute(BinaryOperator *BI);

            // 替换 Add 指令
            Value* substituteAdd(BinaryOperator *BI);

            // 替换 Sub 指令
            Value* substituteSub(BinaryOperator *BI);

            // 替换 And 指令
            Value* substituteAnd(BinaryOperator *BI);
            
            // 替换 Or 指令
            Value* substituteOr(BinaryOperator *BI);

            // 替换 Xor 指令
            Value* substituteXor(BinaryOperator *BI);
            
    };

    FunctionPass* createMBAObfuscationPass(bool enable);
}