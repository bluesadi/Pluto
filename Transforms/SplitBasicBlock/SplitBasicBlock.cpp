#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/IR/Instructions.h"
#include <vector>
using std::vector;
using namespace llvm;

// 可选的参数，指定一个基本块会被分裂成几个基本块，默认值为 2
static cl::opt<int> SplitNum("split_num", cl::init(2), cl::desc("Split <split_num> time(s) each BB"));

namespace{
    class SplitBasicBlock : public FunctionPass {
        public:
            static char ID;
            SplitBasicBlock() : FunctionPass(ID) {}

            bool runOnFunction(Function &F);

            void split(BasicBlock *BB);

            bool containsPHI(BasicBlock *BB);
    };
}

bool SplitBasicBlock::runOnFunction(Function &F){
    // 第一步：保存原先的所有基本块
    vector<BasicBlock*> origBB;
    for(BasicBlock &BB : F){
        origBB.push_back(&BB);
    }
    // 第二步：对每个不包含 PHI 指令的基本块执行分裂操作
    for(BasicBlock *BB : origBB){
        if(!containsPHI(BB)){
            split(BB);
        }
    }
    return true;
}

void SplitBasicBlock::split(BasicBlock *BB){
    BasicBlock *curBB = BB;
    // 计算分裂后每个基本块的大小
    int splitSize = BB->size() / SplitNum;
    if(splitSize){
        for(int i = 0;i < SplitNum;i ++){
            int cnt = 0;
            for(Instruction &I : *curBB){
                if(++cnt == splitSize){
                    // 在 I 指令处对基本块进行分割
                    curBB = curBB->splitBasicBlock(&I);
                    break;
                }
            }
        }
    }
}

// 判断基本块中是否存在 PHI 指令
bool SplitBasicBlock::containsPHI(BasicBlock *BB){
    for(Instruction &I : *BB){
        if(isa<PHINode>(&I)){
            return true;
        }
    }
    return false;
}

char SplitBasicBlock::ID = 0;
static RegisterPass<SplitBasicBlock> X("split", "Split a basic block into multiple basic blocks.");