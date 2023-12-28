#include "llvm/Transforms/Obfuscation/Flattening.h"
#include "llvm/Analysis/IteratedDominanceFrontier.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include "llvm/Transforms/Utils/Local.h"
#include <algorithm>
#include <queue>
#include <vector>

using std::find;
using std::queue;
using std::vector;

void fixVariables(Function &F, vector<BasicBlock *> &normalBlocks) {
    vector<PHINode *> origPHI;
    vector<Instruction *> origReg;
    BasicBlock &entryBB = F.getEntryBlock();

    for (BasicBlock *BB : normalBlocks) {
        for (Instruction &I : *BB) {
            if (PHINode *PN = dyn_cast<PHINode>(&I)) {
                origPHI.push_back(PN);
            }
        }
    }
    for (PHINode *PN : origPHI) {
        DemotePHIToStack(PN, entryBB.getTerminator());
    }

    for (BasicBlock *BB : normalBlocks) {
        for (Instruction &I : *BB) {
            if (!(isa<AllocaInst>(&I) && I.getParent() == &entryBB) && I.isUsedOutsideOfBlock(BB)) {
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

    // 如果只有一个基本块则无需平坦化
    // No need to do flattening if only there is only one block
    if (F.size() <= 1) {
        return PreservedAnalyses::all();
    }

    vector<BasicBlock *> normalBlocks;
    queue<BasicBlock *> queue;
    queue.push(&F.getEntryBlock());
    while (queue.size()) {
        BasicBlock *BB = queue.front();
        queue.pop();
        if (find(normalBlocks.begin(), normalBlocks.end(), BB) != normalBlocks.end()) {
            continue;
        }
        normalBlocks.push_back(BB);
        if (InvokeInst *invoke = dyn_cast_or_null<InvokeInst>(BB->getTerminator())) {
            queue.push(invoke->getNormalDest());
        } else {
            for (size_t i = 0; i < BB->getTerminator()->getNumSuccessors(); i++) {
                BasicBlock *successor = BB->getTerminator()->getSuccessor(i);
                queue.push(successor);
            }
        }
    }

    BasicBlock &entryBB = F.getEntryBlock();
    normalBlocks.erase(normalBlocks.begin());

    // 如果入口块的末尾是条件跳转，单独分离
    // If the entry block ends with a conditional branch, seperate it as a new block
    if (entryBB.getTerminator()->getNumSuccessors() > 1) {
        BasicBlock *newBB = entryBB.splitBasicBlock(entryBB.getTerminator(), "newBB");
        normalBlocks.insert(normalBlocks.begin(), newBB);
    }

    for (BasicBlock *BB : normalBlocks) {
        if (InvokeInst *invoke = dyn_cast_or_null<InvokeInst>(BB->getTerminator())) {
            BasicBlock *bridgeBB = BasicBlock::Create(context, "bridgeBB", &F, invoke->getNormalDest());
            invoke->getNormalDest()->replacePhiUsesWith(BB, bridgeBB);
            builder.SetInsertPoint(bridgeBB);
            builder.CreateBr(invoke->getNormalDest());
            invoke->setNormalDest(bridgeBB);
        }
    }

    // 创建分发块和返回块
    // Create the dispatch block and return block
    BasicBlock *dispatchBB = BasicBlock::Create(context, "dispatchBB", &F, &entryBB);
    BasicBlock *returnBB = BasicBlock::Create(context, "returnBB", &F, &entryBB);
    BranchInst::Create(dispatchBB, returnBB);
    entryBB.moveBefore(dispatchBB);

    // 去除入口块末尾的跳转，并使入口块跳转到dispatchBB
    // Make the entry block go to the dispatchBB directly
    entryBB.getTerminator()->eraseFromParent();
    BranchInst *brDispatchBB = BranchInst::Create(dispatchBB, &entryBB);

    builder.SetInsertPoint(brDispatchBB);

    // 在入口块插入alloca和store指令创建并初始化switch变量，初始值为随机值
    // Now insert an alloca and a store instruction at the end of entry block, and initialize the
    // switch variable with a random value.
    uint32_t randNum = cryptoutils->get_uint32_t();
    AllocaInst *swVarPtr = builder.CreateAlloca(Type::getInt32Ty(context), 0, "swVar.ptr");
    builder.CreateStore(ConstantInt::get(Type::getInt32Ty(context), randNum), swVarPtr);

    // 在分发块插入load指令读取switch变量
    // Insert a load instruction at the end of dispatch block
    builder.SetInsertPoint(dispatchBB);
    LoadInst *swVar = builder.CreateLoad(Type::getInt32Ty(context), swVarPtr, false, "swVar");

    // 在分发块插入switch指令实现基本块的调度
    // Insert a switch instruction to implement block dispatching
    BasicBlock *swDefault = BasicBlock::Create(context, "swDefault", &F, returnBB);
    builder.SetInsertPoint(swDefault);
    builder.CreateBr(returnBB);
    builder.SetInsertPoint(dispatchBB);
    SwitchInst *swInst = builder.CreateSwitch(swVar, swDefault, normalBlocks.size());

    // 将原基本块插入到返回块之前，并分配case值
    // Insert original basic blocks before return block and assign a random case value for each one.
    for (BasicBlock *BB : normalBlocks) {
        BB->moveBefore(returnBB);
        swInst->addCase(ConstantInt::get(Type::getInt32Ty(context), randNum), BB);
        randNum = cryptoutils->get_uint32_t();
    }

    // 在每个基本块最后添加修改switch变量的指令和跳转到返回块的指令
    // Insert a store instruction at the end of each block to modify swVar, and make them jump back
    // to dispatch block then.
    for (BasicBlock *BB : normalBlocks) {
        // 跳过没有后继的基本块
        // Skip blocks with no successor
        if (BB->getTerminator()->getNumSuccessors() == 0) {
            continue;
        }
        // 非条件跳转
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
        // 条件跳转
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
    fixVariables(F, normalBlocks);
    return PreservedAnalyses::none();
}