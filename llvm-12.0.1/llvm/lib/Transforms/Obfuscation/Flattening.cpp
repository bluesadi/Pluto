#include "llvm/Transforms/Obfuscation/Flattening.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include "llvm/Transforms/Obfuscation/Utils.h"
#include <vector>

using Utils::fixStack;

namespace Flattening {
bool visit(Function &F) {
    auto &context = F.getContext();
    // 如果只有一个基本块则无需平坦化
    // No need to do flattening if only one block presents
    if (F.size() <= 1) {
        return false;
    }

    // 将除入口块（第一个基本块）以外的基本块保存到一个vector容器中，便于后续处理
    // Store all basic blocks to the origBB vector except for the entry block.
    std::vector<BasicBlock *> origBB;
    for (BasicBlock &BB : F) {
        origBB.push_back(&BB);
    }
    origBB.erase(origBB.begin());

    BasicBlock &entryBB = F.getEntryBlock();

    // 如果入口块的末尾是条件跳转，单独分离
    // If the entry block's last instruction is a conditional branch, seperate it as a new block.
    if (BranchInst *br = dyn_cast<BranchInst>(entryBB.getTerminator())) {
        if (br->isConditional()) {
            BasicBlock *newBB = entryBB.splitBasicBlock(br, "newBB");
            origBB.insert(origBB.begin(), newBB);
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

    // 在入口块插入alloca和store指令创建并初始化switch变量，初始值为随机值
    // Now insert an alloca and a store instruction at the end of entry block, and initialize the
    // switch variable with a random value.
    uint32_t randNumCase = cryptoutils->get_uint32_t();
    AllocaInst *swVarPtr = new AllocaInst(Type::getInt32Ty(context), 0, "swVar.ptr", brDispatchBB);
    new StoreInst(ConstantInt::get(Type::getInt32Ty(context), randNumCase), swVarPtr, brDispatchBB);

    // 在分发块插入load指令读取switch变量
    // Insert a load instruction at the end of dispatch block
    LoadInst *swVar = new LoadInst(Type::getInt32Ty(context), swVarPtr, "swVar", false, dispatchBB);

    // 在分发块插入switch指令实现基本块的调度
    // Insert a switch instruction to implement block dispatching
    BasicBlock *swDefault = BasicBlock::Create(context, "swDefault", &F, returnBB);
    BranchInst::Create(returnBB, swDefault);
    SwitchInst *swInst = SwitchInst::Create(swVar, swDefault, 0, dispatchBB);

    // 将原基本块插入到返回块之前，并分配case值
    // Insert original basic blocks before return block and assign a random case value for each one.
    for (BasicBlock *BB : origBB) {
        BB->moveBefore(returnBB);
        swInst->addCase(ConstantInt::get(Type::getInt32Ty(context), randNumCase), BB);
        randNumCase = cryptoutils->get_uint32_t();
    }

    // 在每个基本块最后添加修改switch变量的指令和跳转到返回块的指令
    // Insert a store instruction at the end of each block to modify swVar, and make them jump back
    // to dispatch block then.
    for (BasicBlock *BB : origBB) {
        // 忽略returnBB
        // Ignore return blocks
        if (BB->getTerminator()->getNumSuccessors() == 0) {
            continue;
        }
        // 非条件跳转
        // Branch
        else if (BB->getTerminator()->getNumSuccessors() == 1) {
            BasicBlock *sucBB = BB->getTerminator()->getSuccessor(0);
            BB->getTerminator()->eraseFromParent();
            ConstantInt *numCase = swInst->findCaseDest(sucBB);
            new StoreInst(numCase, swVarPtr, BB);
            BranchInst::Create(returnBB, BB);
        }
        // 条件跳转
        // Conditional branch
        else if (BB->getTerminator()->getNumSuccessors() == 2) {
            ConstantInt *numCaseTrue = swInst->findCaseDest(BB->getTerminator()->getSuccessor(0));
            ConstantInt *numCaseFalse = swInst->findCaseDest(BB->getTerminator()->getSuccessor(1));
            BranchInst *br = cast<BranchInst>(BB->getTerminator());
            SelectInst *sel = SelectInst::Create(br->getCondition(), numCaseTrue, numCaseFalse, "",
                                                 BB->getTerminator());
            BB->getTerminator()->eraseFromParent();
            new StoreInst(sel, swVarPtr, BB);
            BranchInst::Create(returnBB, BB);
        }
    }
    fixStack(F);
    return true;
}
} // namespace Flattening

PreservedAnalyses Pluto::Flattening::run(Function &F, FunctionAnalysisManager &AM) {
    return ::Flattening::visit(F) ? PreservedAnalyses::none() : PreservedAnalyses::all();
}

bool Pluto::LegacyFlattening::runOnFunction(Function &F) { return ::Flattening::visit(F); }

void Pluto::LegacyFlattening::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.addRequiredID(LowerSwitchID);
}