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
            void substituteAdd(BinaryOperator *BI);

            // 替换 Sub 指令
            void substituteSub(BinaryOperator *BI);

            // 替换 And 指令
            void substituteAnd(BinaryOperator *BI);
            
            // 替换 Or 指令
            void substituteOr(BinaryOperator *BI);

            // 替换 Xor 指令
            void substituteXor(BinaryOperator *BI);
            
    };

    FunctionPass* createMBAObfuscationPass(bool enable);
}