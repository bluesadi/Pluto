#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Transforms/Utils.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Transforms/Utils/Local.h"
#include "SplitBasicBlock.h"
#include "Utils.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace llvm;
using std::vector;
 
namespace{
    class Flattening : public FunctionPass{
        public:
            static char ID;
            Flattening() : FunctionPass(ID){
                srand(time(0));
            }

            // 对函数 F 进行平坦化
            void flatten(Function &F);
    
            bool runOnFunction(Function &F);

    };
}

bool Flattening::runOnFunction(Function &F){
    INIT_CONTEXT(F);
    FunctionPass *pass = createSplitBasicBlockPass();
    pass->runOnFunction(F);
    flatten(F);
    return true;
}
 
void Flattening::flatten(Function &F){
    // 基本块数量不超过1则无需平坦化
    if(F.size() <= 1){
        return;
    }
    // Lower switch
    // 调用 Lower switch 会导致崩溃，解决方法未知
    //FunctionPass *pass = createLowerSwitchPass();
    //pass->runOnFunction(F);
    // 将除入口块（第一个基本块）以外的基本块保存到一个 vector 容器中，便于后续处理
    // 首先保存所有基本块
    vector<BasicBlock*> origBB;
    for(BasicBlock &BB: F){
        origBB.push_back(&BB);
    }
    // 从vector中去除第一个基本块
    origBB.erase(origBB.begin());
    BasicBlock &entryBB = F.getEntryBlock();
    // 如果第一个基本块的末尾是条件跳转，单独分离
    if(BranchInst *br = dyn_cast<BranchInst>(entryBB.getTerminator())){
        if(br->isConditional()){
            BasicBlock *newBB = entryBB.splitBasicBlock(br, "newBB");
            origBB.insert(origBB.begin(), newBB);
        }
    }

    // 创建分发块和返回块
    BasicBlock *dispatchBB = BasicBlock::Create(F.getContext(), "dispatchBB", &F, &entryBB);
    BasicBlock *returnBB = BasicBlock::Create(F.getContext(), "returnBB", &F, &entryBB);
    BranchInst::Create(dispatchBB, returnBB);
    entryBB.moveBefore(dispatchBB);
    // 去除第一个基本块末尾的跳转
    entryBB.getTerminator()->eraseFromParent();
    // 使第一个基本块跳转到dispatchBB
    BranchInst *brDispatchBB = BranchInst::Create(dispatchBB, &entryBB);

    // 在入口块插入alloca和store指令创建并初始化switch变量，初始值为随机值
    int randNumCase = rand();
    AllocaInst *swVarPtr = new AllocaInst(TYPE_I32, 0, "swVar.ptr", brDispatchBB);
    new StoreInst(CONST_I32(randNumCase), swVarPtr, brDispatchBB);
    // 在分发块插入load指令读取switch变量
    LoadInst *swVar = new LoadInst(TYPE_I32, swVarPtr, "swVar", false, dispatchBB);
    // 在分发块插入switch指令实现基本块的调度
    BasicBlock *swDefault = BasicBlock::Create(F.getContext(), "swDefault", &F, returnBB);
    BranchInst::Create(returnBB, swDefault);
    SwitchInst *swInst = SwitchInst::Create(swVar, swDefault, 0, dispatchBB);
    // 将原基本块插入到返回块之前，并分配case值
    for(BasicBlock *BB : origBB){
        BB->moveBefore(returnBB);
        swInst->addCase(CONST_I32(randNumCase), BB);
        randNumCase = rand();
    }

    // 在每个基本块最后添加修改switch变量的指令和跳转到返回块的指令
    for(BasicBlock *BB : origBB){
        // retn BB
        if(BB->getTerminator()->getNumSuccessors() == 0){
            continue;
        }
        // 非条件跳转
        else if(BB->getTerminator()->getNumSuccessors() == 1){
            BasicBlock *sucBB = BB->getTerminator()->getSuccessor(0);
            BB->getTerminator()->eraseFromParent();
            ConstantInt *numCase = swInst->findCaseDest(sucBB);
            new StoreInst(numCase, swVarPtr, BB);
            BranchInst::Create(returnBB, BB);
        }
        // 条件跳转
        else if(BB->getTerminator()->getNumSuccessors() == 2){
            ConstantInt *numCaseTrue = swInst->findCaseDest(BB->getTerminator()->getSuccessor(0));
            ConstantInt *numCaseFalse = swInst->findCaseDest(BB->getTerminator()->getSuccessor(1));
            BranchInst *br = cast<BranchInst>(BB->getTerminator());
            SelectInst *sel = SelectInst::Create(br->getCondition(), numCaseTrue, numCaseFalse, "", BB->getTerminator());
            BB->getTerminator()->eraseFromParent();
            new StoreInst(sel, swVarPtr, BB);
            BranchInst::Create(returnBB, BB);
        }
    }
    fixStack(F);
}
 
char Flattening::ID = 0;
static RegisterPass<Flattening> X("fla", "Flatten the basic blocks in each function.");