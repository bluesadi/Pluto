#include "z3++.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {
    
    int64_t* generateLinearMBA(int termsNumber);

    Value* insertLinearMBA(int64_t *params, BinaryOperator *insertBefore);

    Value* insertPolynomialMBA(Value *linearMBAExpr, BinaryOperator *insertBefore);

}