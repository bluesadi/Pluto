// #include "z3++.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {

int64_t *generateLinearMBA(int termsNumber);

Value *insertLinearMBA(int64_t *params, Instruction *insertBefore);

Value *insertPolynomialMBA(Value *linearMBAExpr, Instruction *insertBefore);

} // namespace llvm