#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Transforms/Obfuscation/SplitBasicBlock.h"
#include <vector>
using std::vector;
using namespace llvm;

// 可选的参数，指定一个基本块会被分裂成几个基本块，默认值为 2
static cl::opt<int> SplitNum("split-num", cl::init(0), cl::desc("Split <split_num> time(s) each BB"));

bool SplitBasicBlock::runOnFunction(Function &F){
    if(SplitNum > 0){
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
    return false;
}

void SplitBasicBlock::split(BasicBlock *BB){
    // 计算分裂后每个基本块的大小
    // 原基本块的大小 / 分裂数目（向上取整）
    int splitSize = (BB->size() + SplitNum - 1) / SplitNum;
    for(int i = 1;i < SplitNum;i ++){
        BasicBlock *curBB = BB;
        int cnt = 0;
        for(Instruction &I : *curBB){
            if(cnt++ == splitSize){
                // 在 I 指令处对基本块进行分割
                curBB = curBB->splitBasicBlock(&I);
                break;
            }
        }
    }
}

bool SplitBasicBlock::containsPHI(BasicBlock *BB){
    for(Instruction &I : *BB){
        if(isa<PHINode>(&I)){
            return true;
        }
    }
    return false;
}

FunctionPass* llvm::createSplitBasicBlockPass(){
    return new SplitBasicBlock();
}

char SplitBasicBlock::ID = 0;