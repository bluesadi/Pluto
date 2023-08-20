#include "llvm/Transforms/Obfuscation/IndirectBranches.h"

#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Obfuscation/MbaObfuscation.h"
#include "llvm/Transforms/Utils/LowerSwitch.h"
#include <algorithm>
#include <map>
#include <random>
#include <vector>

namespace Pluto {

PreservedAnalyses Pluto::IndirectBranches::run(Function &F, FunctionAnalysisManager &AM) {
    LLVMContext &context = F.getContext();
    IRBuilder<> builder(context);

    std::vector<BasicBlock *> destinations;
    for (BasicBlock &BB : F) {
        for (Instruction &I : BB) {
            if (BranchInst *br = dyn_cast<BranchInst>(&I)) {
                for (BasicBlock *destination : br->successors()) {
                    destinations.push_back(destination);
                }
            }
        }
    }

    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(destinations.begin(), destinations.end(), rng);

    std::vector<Constant *> destAddrs;
    for (BasicBlock *dest : destinations) {
        destAddrs.push_back(BlockAddress::get(dest));
    }

    // Save destination addresses to global variable
    ArrayRef<Constant *> destAddrsRef(destAddrs);
    Constant *destAddrsArray = ConstantArray::get(
        ArrayType::get(Type::getInt64Ty(context), destAddrs.size()), destAddrsRef);
    ArrayType *functionTableType = ArrayType::get(Type::getInt64Ty(context), destAddrs.size());
    GlobalVariable *functionTable = new GlobalVariable(
        *F.getParent(), functionTableType, false, GlobalVariable::PrivateLinkage, destAddrsArray);

    for (BasicBlock &BB : F) {
        for (Instruction &I : BB) {
            if (BranchInst *br = dyn_cast<BranchInst>(&I)) {
                builder.SetInsertPoint(br);
                if (br->getNumSuccessors() == 1) {
                    BasicBlock *successor = br->getSuccessor(0);
                    BlockAddress *addr = BlockAddress::get(successor);
                    int i = 0;
                    for (BasicBlock *destination : destinations) {
                        if (destination == successor) {
                            break;
                        }
                        i += 1;
                    }

                    // Make index able to be obfuscated by MbaObfuscation
                    AllocaInst *indexPtr = builder.CreateAlloca(Type::getInt32Ty(context));
                    builder.CreateStore(ConstantInt::get(Type::getInt32Ty(context), 0), indexPtr);
                    Value *index =
                        builder.CreateAdd(builder.CreateLoad(indexPtr),
                                          ConstantInt::get(Type::getInt32Ty(context), i));

                    // Replace the original BranchInst
                    auto GEP = builder.CreateGEP(
                        functionTable, {ConstantInt::get(Type::getInt32Ty(context), 0), index});
                    builder.CreateIndirectBr(builder.CreateLoad(GEP), 1)->addDestination(successor);
                } else if (br->getNumSuccessors() == 2) {
                    BasicBlock *iftrue = br->getSuccessor(0);
                    BasicBlock *iffalse = br->getSuccessor(1);
                    int i = 0, i0 = -1, i1 = -1;
                    for (BasicBlock *destination : destinations) {
                        if (destination == iftrue) {
                            i0 = i;
                        } else if (destination == iffalse) {
                            i1 = i;
                        }
                        if (i0 >= 0 && i1 >= 0) {
                            break;
                        }
                        i += 1;
                    }

                    // Make index able to be obfuscated by MbaObfuscation
                    AllocaInst *index0Ptr = builder.CreateAlloca(Type::getInt32Ty(context));
                    builder.CreateStore(ConstantInt::get(Type::getInt32Ty(context), 0), index0Ptr);
                    Value *index0 =
                        builder.CreateAdd(builder.CreateLoad(index0Ptr),
                                          ConstantInt::get(Type::getInt32Ty(context), i0));
                    AllocaInst *index1Ptr = builder.CreateAlloca(Type::getInt32Ty(context));
                    builder.CreateStore(ConstantInt::get(Type::getInt32Ty(context), 0), index1Ptr);
                    Value *index1 =
                        builder.CreateAdd(builder.CreateLoad(index1Ptr),
                                          ConstantInt::get(Type::getInt32Ty(context), i1));

                    // Replace the original BranchInst
                    auto GEP0 = builder.CreateGEP(
                        functionTable, {ConstantInt::get(Type::getInt32Ty(context), 0), index0});
                    auto GEP1 = builder.CreateGEP(
                        functionTable, {ConstantInt::get(Type::getInt32Ty(context), 0), index1});
                    Value *addr = builder.CreateSelect(br->getCondition(), builder.CreateLoad(GEP0),
                                                       builder.CreateLoad(GEP1));
                    IndirectBrInst *ibr = builder.CreateIndirectBr(addr, 2);
                    ibr->addDestination(iftrue);
                    ibr->addDestination(iffalse);
                }
            }
        }
    }

    return PreservedAnalyses::all();
}

}; // namespace Pluto