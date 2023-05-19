#include "llvm/Transforms/Obfuscation/Utils.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Transforms/Utils/Local.h"
#include <vector>
using std::vector;

void Utils::fixStack(Function &F) {
    vector<PHINode *> origPHI;
    vector<Instruction *> origReg;
    BasicBlock &entryBB = F.getEntryBlock();
    for (BasicBlock &BB : F) {
        for (Instruction &I : BB) {
            if (PHINode *PN = dyn_cast<PHINode>(&I)) {
                origPHI.push_back(PN);
            } else if (!(isa<AllocaInst>(&I) && I.getParent() == &entryBB) &&
                       I.isUsedOutsideOfBlock(&BB)) {
                origReg.push_back(&I);
            }
        }
    }
    for (PHINode *PN : origPHI) {
        DemotePHIToStack(PN, entryBB.getTerminator());
    }
    for (Instruction *I : origReg) {
        DemoteRegToStack(*I, entryBB.getTerminator());
    }
}