#ifndef LLVM_SPLIT_BASIC_BLOCK_H
#define LLVM_SPLIT_BASIC_BLOCK_H

#include "llvm/Pass.h"
#include <llvm/IR/Function.h>

namespace llvm{
    class SplitBasicBlock : public FunctionPass {
        public:
            static char ID;

            SplitBasicBlock() : FunctionPass(ID) { }

            bool runOnFunction(Function &F);

            // 对单个基本块执行分裂操作
            void split(BasicBlock *BB);

            //判断一个基本块中是否包含 PHI指令(PHINode)
            bool containsPHI(BasicBlock *BB);
    };

    FunctionPass* createSplitBasicBlockPass();
}

#endif // LLVM_SPLIT_BASIC_BLOCK_H