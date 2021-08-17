#include "Utils.h"
#include <vector>
#include "llvm/IR/Instructions.h"
#include "llvm/Transforms/Utils/Local.h"
#include "llvm/Transforms/Utils/ValueMapper.h"
#include "llvm/Transforms/Utils/Cloning.h"
using std::vector;
using namespace llvm;

LLVMContext *CONTEXT = nullptr;

void llvm::fixStack(Function &F) {
    vector<PHINode*> origPHI;
    vector<Instruction*> origReg;
    BasicBlock &entryBB = F.getEntryBlock();
    for(BasicBlock &BB : F){
        for(Instruction &I : BB){
            if(PHINode *PN = dyn_cast<PHINode>(&I)){
                origPHI.push_back(PN);
            }else if(!(isa<AllocaInst>(&I) && I.getParent() == &entryBB) 
                && I.isUsedOutsideOfBlock(&BB)){
                origReg.push_back(&I);
            }
        }
    }
    for(PHINode *PN : origPHI){
        DemotePHIToStack(PN, entryBB.getTerminator());
    }
    for(Instruction *I : origReg){
        DemoteRegToStack(*I, entryBB.getTerminator());
    }
}

BasicBlock* llvm::createCloneBasicBlock(BasicBlock *BB){
    // 克隆之前先修复所有逃逸变量
    for(Instruction &I : *BB){
        if(I.isUsedOutsideOfBlock(BB)){
            AllocaInst *a = DemoteRegToStack(I, &BB->getParent()->getEntryBlock());
        }
    }
    ValueToValueMapTy VMap;
    BasicBlock * alteredBB = CloneBasicBlock(BB, VMap, BB->getName() + "cloneBB", BB->getParent());
    // 对克隆基本块的引用进行修复
    for(Instruction &I : *alteredBB){
        for(int i = 0;i < I.getNumOperands();i ++){
            Value *V = MapValue(I.getOperand(i), VMap);
            if(V){
                I.setOperand(i, V);
            }
        }
    }
    return alteredBB;
}