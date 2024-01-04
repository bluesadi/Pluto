#include "llvm/Analysis/IteratedDominanceFrontier.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include "llvm/Transforms/Obfuscation/Flattening.h"
#include "llvm/Transforms/Utils/Local.h"
#include <algorithm>
#include <queue>
#include <vector>

using std::find;
using std::queue;
using std::vector;

void fixVariables(Function &F) {
    vector<PHINode *> origPHI;
    vector<Instruction *> origReg;
    BasicBlock &entryBB = F.getEntryBlock();

    for (BasicBlock &BB : F) {
        for (Instruction &I : BB) {
            if (PHINode *PN = dyn_cast<PHINode>(&I)) {
                origPHI.push_back(PN);
            }
        }
    }
    for (PHINode *PN : origPHI) {
        DemotePHIToStack(PN, entryBB.getTerminator());
    }

    for (BasicBlock &BB : F) {
        for (Instruction &I : BB) {
            if (!(isa<AllocaInst>(&I) && I.getParent() == &entryBB) && I.isUsedOutsideOfBlock(&BB)) {
                origReg.push_back(&I);
            }
        }
    }
    for (Instruction *I : origReg) {
        DemoteRegToStack(*I, entryBB.getTerminator());
    }
}

PreservedAnalyses Pluto::Flattening::run(Function &F, FunctionAnalysisManager &AM) {
    auto &context = F.getContext();
    IRBuilder<> builder(context);

    // No need to do flattening if only there is only one block
    if (F.size() <= 1) {
        return PreservedAnalyses::all();
    }

    vector<BasicBlock *> origBB;

    for (BasicBlock &BB : F) {
        origBB.push_back(&BB);
    }

    BasicBlock &entryBB = F.getEntryBlock();
    origBB.erase(origBB.begin());

    // If the entry block ends with a conditional branch, seperate it as a new block
    if (entryBB.getTerminator()->getNumSuccessors() > 1) {
        BasicBlock *newBB = entryBB.splitBasicBlock(entryBB.getTerminator(), "newBB");
        origBB.insert(origBB.begin(), newBB);
    }

    // This is for register demotion
    // The return value of the invoke instruction will be store into stack in the bridge block
    for (BasicBlock *BB : origBB) {
        if (InvokeInst *invoke = dyn_cast_or_null<InvokeInst>(BB->getTerminator())) {
            BasicBlock *bridgeBB = BasicBlock::Create(context, "bridgeBB", &F, invoke->getNormalDest());
            invoke->getNormalDest()->replacePhiUsesWith(BB, bridgeBB);
            builder.SetInsertPoint(bridgeBB);
            builder.CreateBr(invoke->getNormalDest());
            invoke->setNormalDest(bridgeBB);
        }
    }

    // Create the dispatch block and return block
    BasicBlock *dispatchBB = BasicBlock::Create(context, "dispatchBB", &F, &entryBB);
    BasicBlock *returnBB = BasicBlock::Create(context, "returnBB", &F, &entryBB);
    BranchInst::Create(dispatchBB, returnBB);
    entryBB.moveBefore(dispatchBB);

    // Make the entry block go to the dispatchBB directly
    entryBB.getTerminator()->eraseFromParent();
    BranchInst *brDispatchBB = BranchInst::Create(dispatchBB, &entryBB);

    builder.SetInsertPoint(brDispatchBB);

    // Now insert an alloca and a store instruction at the end of entry block, and initialize the switch variable with
    // a random value.
    uint32_t randNum = cryptoutils->get_uint32_t();
    AllocaInst *swVarPtr = builder.CreateAlloca(Type::getInt32Ty(context), 0, "swVar.ptr");
    builder.CreateStore(ConstantInt::get(Type::getInt32Ty(context), randNum), swVarPtr);

    // Insert a load instruction at the end of dispatch block
    builder.SetInsertPoint(dispatchBB);
    LoadInst *swVar = builder.CreateLoad(Type::getInt32Ty(context), swVarPtr, false, "swVar");

    // Insert a switch instruction to dispatch blocks
    BasicBlock *swDefault = BasicBlock::Create(context, "swDefault", &F, returnBB);
    builder.SetInsertPoint(swDefault);
    builder.CreateBr(returnBB);
    builder.SetInsertPoint(dispatchBB);
    SwitchInst *swInst = builder.CreateSwitch(swVar, swDefault, origBB.size());

    // Record used random numbers to avoid depulicate case values in switch
    std::set<uint32_t> usedNum;

    // Insert original basic blocks before return block and assign a random case value for each one.
    for (BasicBlock *BB : origBB) {
        // Do not add error handling blocks into switch
        if (BB->isEHPad()) {
            continue;
        }
        usedNum.insert(randNum);
        BB->moveBefore(returnBB);
        swInst->addCase(ConstantInt::get(Type::getInt32Ty(context), randNum), BB);
        do {
            randNum = cryptoutils->get_uint32_t();
        } while (find(usedNum.begin(), usedNum.end(), randNum) != usedNum.end());
    }

    // Insert a store instruction at the end of each block to modify swVar, and make them jump back to dispatch block.
    for (BasicBlock *BB : origBB) {
        // Skip blocks with no successor
        if (BB->getTerminator()->getNumSuccessors() == 0) {
            continue;
        }
        // Branch
        else if (BB->getTerminator()->getNumSuccessors() == 1) {
            BasicBlock *sucBB = BB->getTerminator()->getSuccessor(0);
            ConstantInt *numCase = swInst->findCaseDest(sucBB);
            if (numCase) {
                if (BranchInst *br = dyn_cast_or_null<BranchInst>(BB->getTerminator())) {
                    BB->getTerminator()->eraseFromParent();
                    builder.SetInsertPoint(BB);
                    builder.CreateStore(numCase, swVarPtr);
                    builder.CreateBr(returnBB);
                }
            }
        }
        // Conditional branch
        else if (BB->getTerminator()->getNumSuccessors() == 2) {
            ConstantInt *numIfTrue = swInst->findCaseDest(BB->getTerminator()->getSuccessor(0));
            ConstantInt *numIfFalse = swInst->findCaseDest(BB->getTerminator()->getSuccessor(1));
            if (numIfTrue && numIfFalse) {
                if (BranchInst *br = dyn_cast_or_null<BranchInst>(BB->getTerminator())) {
                    Value *cond = br->getCondition();
                    builder.SetInsertPoint(BB);
                    builder.CreateStore(builder.CreateSelect(cond, numIfTrue, numIfFalse), swVarPtr);
                    builder.CreateBr(returnBB);
                    br->eraseFromParent();
                }
            }
        }
    }
    fixVariables(F);
    return PreservedAnalyses::none();
}