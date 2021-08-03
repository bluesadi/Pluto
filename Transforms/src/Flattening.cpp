#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Transforms/Utils.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Transforms/Utils/Local.h"
#include "SplitBasicBlock.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace llvm;
using std::vector;
 
// 混淆次数，混淆次数越多混淆结果越复杂
static cl::opt<int> obfuTimes("fla_loop", cl::init(1), cl::desc("Obfuscate a function <fla_loop> time(s)."));

namespace{
    class Flattening : public FunctionPass{
        public:
            static char ID;
            Flattening() : FunctionPass(ID){}

            // 对函数 F 进行平坦化
            void flatten(Function &F);
    
            bool runOnFunction(Function &F);

            // 栈修复
            void fixStack(Function &F);
    };
}

bool Flattening::runOnFunction(Function &F){
    FunctionPass *pass = createSplitBasicBlockPass();
    pass->runOnFunction(F);
    for(int i = 0;i < obfuTimes;i ++){
        flatten(F);
    }
    return true;
}
 
void Flattening::flatten(Function &F){
    // Lower switch
    // 调用 Lower switch 会导致崩溃，原因不明
    //FunctionPass *pass = createLowerSwitchPass();
    //pass->runOnFunction(F);
    IntegerType *i32 = Type::getInt32Ty(F.getContext());
    // 遍历函数所有基本块，将其存到vector中
    vector<BasicBlock*> origBB;
    for(BasicBlock &BB: F){
        origBB.push_back(&BB);
    }
    // 基本块数量不超过1则无需平坦化
    if(origBB.size() <= 1){
        return;
    }
    // 从vector中去除第一个基本块
    origBB.erase(origBB.begin());
    BasicBlock &firstBB = F.front();
    // 如果第一个基本块的末尾是条件跳转
    if(isa<BranchInst>(firstBB.getTerminator())){
        BranchInst *br = cast<BranchInst>(firstBB.getTerminator());
        if(br->isConditional()){
            BasicBlock *newBB = firstBB.splitBasicBlock(br, "newBB");
            origBB.insert(origBB.begin(), newBB);
        }
    }
    // 创建循环
    BasicBlock *loopEntry = BasicBlock::Create(F.getContext(), "loopEntry", &F, &firstBB);
    BasicBlock *loopEnd = BasicBlock::Create(F.getContext(), "loopEnd", &F, &firstBB);
    firstBB.moveBefore(loopEntry);
    // 去除第一个基本块末尾的跳转
    firstBB.getTerminator()->eraseFromParent();
    // 初始化switch on变量
    srand(time(0));
    int randNumCase = rand();
    AllocaInst *swVarPtr = new AllocaInst(i32, 0, "swVar.ptr", &firstBB);
    new StoreInst(ConstantInt::get(i32, randNumCase), swVarPtr, &firstBB);
    // 使第一个基本块跳转到loopEntry
    BranchInst::Create(loopEntry, &firstBB);
    // 在进入loopEntry读取switch on变量
    LoadInst *swVar = new LoadInst(i32, swVarPtr, "swVar", false, loopEntry);
    BranchInst::Create(loopEntry, loopEnd);
    // 初始化switch的default case
    // default case实际上不会被执行
    BasicBlock *swDefault = BasicBlock::Create(F.getContext(), "swDefault", &F, loopEnd);
    BranchInst::Create(loopEnd, swDefault);
    SwitchInst *swInst = SwitchInst::Create(swVar, swDefault, 0, loopEntry);
    // 插入原基本块到switch中，仅是位置意义上的插入，而不是逻辑意义上的
    for(BasicBlock *BB : origBB){
        ConstantInt *numCase = cast<ConstantInt>(ConstantInt::get(i32, randNumCase));
        BB->moveBefore(loopEnd);
        swInst->addCase(numCase,BB);
        randNumCase = rand();
    }
    // 添加case
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
            BranchInst::Create(loopEnd, BB);
            continue;
        }
        // 条件跳转
        else if(BB->getTerminator()->getNumSuccessors() == 2){
            ConstantInt *numCaseTrue = swInst->findCaseDest(BB->getTerminator()->getSuccessor(0));
            ConstantInt *numCaseFalse = swInst->findCaseDest(BB->getTerminator()->getSuccessor(1));
            BranchInst *br = cast<BranchInst>(BB->getTerminator());
            SelectInst *sel = SelectInst::Create(br->getCondition(), numCaseTrue, numCaseFalse, "", BB->getTerminator());
            BB->getTerminator()->eraseFromParent();
            new StoreInst(sel, swVarPtr, BB);
            BranchInst::Create(loopEnd, BB);
        }
    }
    fixStack(F);
}

// Shamefully borrowed from ../Scalar/RegToMem.cpp :(
bool valueEscapes(Instruction *Inst) {
    BasicBlock *BB = Inst->getParent();
    for (Value::use_iterator UI = Inst->use_begin(), E = Inst->use_end(); UI != E;
        ++UI) {
        Instruction *I = cast<Instruction>(*UI);
        if (I->getParent() != BB || isa<PHINode>(I)) {
        return true;
        }
    }
    return false;
}

void Flattening::fixStack(Function &F) {
    // Try to remove phi node and demote reg to stack
    vector<PHINode *> tmpPhi;
    vector<Instruction *> tmpReg;
    BasicBlock *firstBB = &F.front();
    do {
        tmpPhi.clear();
        tmpReg.clear();
        for (BasicBlock &BB : F) {
            for (Instruction &I : BB) {
                if (isa<PHINode>(&I)) {
                    PHINode *PN = cast<PHINode>(&I);
                    tmpPhi.push_back(PN);
                    continue;
                }
                if (!(isa<AllocaInst>(&I) && I.getParent() == firstBB) &&
                    (valueEscapes(&I) || I.isUsedOutsideOfBlock(&BB))) {
                    tmpReg.push_back(&I);
                    continue;
                }
            }
        }
        for (int i = 0; i != tmpReg.size(); ++i) {
            DemoteRegToStack(*tmpReg.at(i), F.begin()->getTerminator());
        }
        for (int i = 0; i != tmpPhi.size(); ++i) {
            DemotePHIToStack(tmpPhi.at(i), F.begin()->getTerminator());
        }
    } while (tmpReg.size() != 0 || tmpPhi.size() != 0);
}
 
char Flattening::ID = 0;
static RegisterPass<Flattening> X("fla", "Flatten the basic blocks in each function.");