
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Transforms/Obfuscation/Utils.h"
#include "llvm/Transforms/Obfuscation/LinearMBAObfuscation.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include "llvm/Transforms/Obfuscation/MBAUtils.h"
#include <vector>
using namespace llvm;

static cl::opt<int> ObfuTimes("linear-mba-times", cl::init(1), cl::desc("Run LinearMBAObfuscation pass <linear-mba-times> time(s)"));
static cl::opt<int> TermsNumber("linear-mba-terms-number", cl::init(10), cl::desc("Choose <linear-mba-terms-number> boolean expr to construct MBA expr."));

bool LinearMBAObfuscation::runOnFunction(Function &F){
    if(enable){
        INIT_CONTEXT(F);
        for(int i = 0;i < ObfuTimes;i ++){
            for(BasicBlock &BB : F){
                std::vector<Instruction*> origInst;
                for(Instruction &I : BB){
                    origInst.push_back(&I);
                }
                for(Instruction *I : origInst){
                    if(isa<BinaryOperator>(I)){
                        BinaryOperator *BI = cast<BinaryOperator>(I);
                        substitute(BI);
                    }
                }
            }
        }
        return true;
    }
    return false;
}

void LinearMBAObfuscation::substitute(BinaryOperator *BI){
    switch (BI->getOpcode()) {
        case BinaryOperator::Add:
            substituteAdd(BI);
            break;
        case BinaryOperator::Sub:
            substituteSub(BI);
            break;
        case BinaryOperator::And:
            substituteAnd(BI);
            break;
        case BinaryOperator::Or:
            substituteOr(BI);
            break;
        case BinaryOperator::Xor:
            substituteXor(BI);
            break;
        default:
            break;
    }
}


void LinearMBAObfuscation::substituteAdd(BinaryOperator *BI){
    int64_t *terms = generateLinearMBA(TermsNumber);
    terms[2] += 1;
    terms[4] += 1;
    Value *mbaExpr = insertLinearMBA(terms, BI);
    BI->replaceAllUsesWith(mbaExpr);
}

void LinearMBAObfuscation::substituteSub(BinaryOperator *BI){
    int64_t *terms = generateLinearMBA(TermsNumber);
    terms[2] += 1;
    terms[4] -= 1;
    Value *mbaExpr = insertLinearMBA(terms, BI);
    BI->replaceAllUsesWith(mbaExpr);
}

void LinearMBAObfuscation::substituteXor(BinaryOperator *BI){
    int64_t *terms = generateLinearMBA(TermsNumber);
    terms[5] += 1;
    Value *mbaExpr = insertLinearMBA(terms, BI);
    BI->replaceAllUsesWith(mbaExpr);
}

void LinearMBAObfuscation::substituteAnd(BinaryOperator *BI){
    int64_t *terms = generateLinearMBA(TermsNumber);
    terms[0] += 1;
    Value *mbaExpr = insertLinearMBA(terms, BI);
    BI->replaceAllUsesWith(mbaExpr);
}

void LinearMBAObfuscation::substituteOr(BinaryOperator *BI){
    int64_t *terms = generateLinearMBA(TermsNumber);
    terms[6] += 1;
    Value *mbaExpr = insertLinearMBA(terms, BI);
    BI->replaceAllUsesWith(mbaExpr);
}

FunctionPass* llvm::createLinearMBAObfuscationPass(bool enable){
    return new LinearMBAObfuscation(enable);
}

char LinearMBAObfuscation::ID = 0;