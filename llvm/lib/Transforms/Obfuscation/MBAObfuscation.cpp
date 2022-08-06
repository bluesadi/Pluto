
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Transforms/Obfuscation/Utils.h"
#include "llvm/Transforms/Obfuscation/MBAObfuscation.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include "llvm/Transforms/Obfuscation/MBAUtils.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace llvm;

static cl::opt<int> ObfuTimes("mba-times", cl::init(1), cl::desc("Run MBAObfuscation pass <mba-times> time(s)"));
static cl::opt<int> ObfuProb("mba-prob", cl::init(40), cl::desc("<mba-prob> percent chance to perform obfuscation for each binary operation."));
static cl::opt<int> TermsNumber("linear-mba-terms", cl::init(10), cl::desc("Choose <linear-mba-terms> boolean exprs to construct the linear MBA expr."));

bool MBAObfuscation::runOnFunction(Function &F){
    if(enable){
        INIT_CONTEXT(F);
        SKIP_IF_SHOULD(F);
        for(int i = 0;i < ObfuTimes;i ++){
            for(BasicBlock &BB : F){
                std::vector<Instruction*> origInst;
                for(Instruction &I : BB){
                    origInst.push_back(&I);
                }
                for(Instruction *I : origInst){
                    if(isa<BinaryOperator>(I)){
                        BinaryOperator *BI = cast<BinaryOperator>(I);
                        if(BI->getOperand(0)->getType()->isIntegerTy() && RANDOM(ObfuProb)){
                            // Do not support 128-bit integers now
                            if(BI->getOperand(0)->getType()->getIntegerBitWidth() > 64){
                                continue;
                            }
                            substitute(BI);
                        }
                    }
                    else{ 
                        for(int i = 0;i < I->getNumOperands();i ++){
                            if(I->getOperand(0)->getType()->isIntegerTy() && RANDOM(ObfuProb)){
                                // error occurs for unknown reasons
                                //if(isa<StoreInst>(I) || isa<CmpInst>(I) || isa<CallInst>(I)){
                                if(isa<StoreInst>(I) || isa<CmpInst>(I)){
                                    substituteConstant(I, i);
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
    return false;
}

void MBAObfuscation::substituteConstant(Instruction *I, int i){
    ConstantInt *val = dyn_cast<ConstantInt>(I->getOperand(i));
    if(val && val->getBitWidth() <= 64){
        int64_t *terms = generateLinearMBA(TermsNumber);
        terms[14] -= val->getValue().getZExtValue();
        Value *mbaExpr = insertLinearMBA(terms, I);
        if(val->getBitWidth() <= 32){
            mbaExpr = insertPolynomialMBA(mbaExpr, I);
        }
        I->setOperand(i, mbaExpr);
    }
}

void MBAObfuscation::substitute(BinaryOperator *BI){
    Value *mbaExpr = nullptr;
    switch (BI->getOpcode()) {
        case BinaryOperator::Add:
            mbaExpr = substituteAdd(BI);
            break;
        case BinaryOperator::Sub:
            mbaExpr = substituteSub(BI);
            break;
        case BinaryOperator::And:
            mbaExpr = substituteAnd(BI);
            break;
        case BinaryOperator::Or:
            mbaExpr = substituteOr(BI);
            break;
        case BinaryOperator::Xor:
            mbaExpr = substituteXor(BI);
            break;
        default:
            break;
    }
    if(mbaExpr){
        if(BI->getOperand(0)->getType()->getIntegerBitWidth() <= 32){
            mbaExpr = insertPolynomialMBA(mbaExpr, BI);
        }
        BI->replaceAllUsesWith(mbaExpr);
    }
}


Value* MBAObfuscation::substituteAdd(BinaryOperator *BI){
    int64_t *terms = generateLinearMBA(TermsNumber);
    terms[2] += 1;
    terms[4] += 1;
    return insertLinearMBA(terms, BI);
}

Value* MBAObfuscation::substituteSub(BinaryOperator *BI){
    int64_t *terms = generateLinearMBA(TermsNumber);
    terms[2] += 1;
    terms[4] -= 1;
    return insertLinearMBA(terms, BI);
}

Value* MBAObfuscation::substituteXor(BinaryOperator *BI){
    int64_t *terms = generateLinearMBA(TermsNumber);
    terms[5] += 1;
    return insertLinearMBA(terms, BI);
}

Value* MBAObfuscation::substituteAnd(BinaryOperator *BI){
    int64_t *terms = generateLinearMBA(TermsNumber);
    terms[0] += 1;
    return insertLinearMBA(terms, BI);
}

Value* MBAObfuscation::substituteOr(BinaryOperator *BI){
    int64_t *terms = generateLinearMBA(TermsNumber);
    terms[6] += 1;
    return insertLinearMBA(terms, BI);
}

FunctionPass* llvm::createMBAObfuscationPass(bool enable){
    return new MBAObfuscation(enable);
}

char MBAObfuscation::ID = 0;