#include <vector>
#include "llvm/IR/Instructions.h"
#include "llvm/Transforms/Utils/Local.h"
#include "llvm/Transforms/Utils/ValueMapper.h"
#include "llvm/Transforms/Utils/Cloning.h"
#include "llvm/Transforms/Obfuscation/Utils.h"
using std::vector;
using namespace llvm;


cl::opt<FilterModeEnum> FilterMode(
    "filter-mode", cl::init(FilterModeEnum::NONE), cl::values(
        clEnumValN(FilterModeEnum::NONE, "none", "Do not filter any functions"),
        clEnumValN(FilterModeEnum::INCLUDE, "include", "Only obfuscate functions with TAG_INCLUDE annotation"),
        clEnumValN(FilterModeEnum::EXCLUDE, "exclude", "Only obfuscate functions without TAG_EXCLUDE annotation")
    ), cl::desc("PlutoObfuscator - HelloWorld Pass"));
    
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
    vector<Instruction*> origReg;
    BasicBlock &entryBB = BB->getParent()->getEntryBlock();
    for(Instruction &I : *BB){
        if(!(isa<AllocaInst>(&I) && I.getParent() == &entryBB) 
            && I.isUsedOutsideOfBlock(BB)){
            origReg.push_back(&I);
        }
    }
    for(Instruction *I : origReg){
        DemoteRegToStack(*I, entryBB.getTerminator());
    }
    ValueToValueMapTy VMap;
    BasicBlock *cloneBB = CloneBasicBlock(BB, VMap, "cloneBB", BB->getParent());
    BasicBlock::iterator origI = BB->begin();
    // 对克隆基本块的引用进行修复
    for(Instruction &I : *cloneBB){
        for(int i = 0;i < I.getNumOperands();i ++){
            Value *V = MapValue(I.getOperand(i), VMap);
            if(V){
                I.setOperand(i, V);
            }
        }
        // SmallVector<std::pair<unsigned, MDNode *>, 4> MDs;
        // I.getAllMetadata(MDs);
        // for(std::pair<unsigned, MDNode *> pair : MDs){
        //     MDNode *MD = MapMetadata(pair.second, VMap);
        //     if(MD){
        //         errs() << "DEBUG1: " << *pair.second << "\n";
        //         errs() << "DEBUG2: " << *MD << "\n";
        //         I.setMetadata(pair.first, MD);
        //     }
        // }
        //I.setDebugLoc(origI->getDebugLoc());
        origI++;
    }
    return cloneBB;
}

// Copied from obfuscator-llvm.
// Reference: https://github.com/obfuscator-llvm/obfuscator/blob/llvm-4.0/lib/Transforms/Utils/Utils.cpp
std::string llvm::readAnnotation(Function *F) {
    std::string annotation = "";
    /* Get annotation variable */
    GlobalVariable *glob = F->getParent()->getGlobalVariable( "llvm.global.annotations" );
    if( glob != NULL ){
        /* Get the array */
        if(ConstantArray* ca = dyn_cast<ConstantArray>(glob->getInitializer())){
            for( unsigned i = 0; i < ca->getNumOperands(); ++i ){
                /* Get the struct */
                if(ConstantStruct* structAn = dyn_cast<ConstantStruct>(ca->getOperand(i))){
                    if(ConstantExpr* expr = dyn_cast<ConstantExpr>(structAn->getOperand(0))){
                        /*
                         * If it's a bitcast we can check if the annotation is concerning
                         * the current function
                         */
                        if(expr->getOpcode() == Instruction::BitCast && expr->getOperand(0) == F){
                            ConstantExpr *note = cast<ConstantExpr>(structAn->getOperand(1));
                            /*
                             * If it's a GetElementPtr, that means we found the variable
                             * containing the annotations
                             */
                            if(note->getOpcode() == Instruction::GetElementPtr){
                                if(GlobalVariable* annoteStr = dyn_cast<GlobalVariable>(note->getOperand(0))){
                                    if(ConstantDataSequential* data = dyn_cast<ConstantDataSequential>(annoteStr->getInitializer())){
                                        if(data->isString()){
                                            annotation += data->getAsString().lower() + " ";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return annotation;
}
