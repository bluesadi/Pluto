#include "llvm/Transforms/Obfuscation/MBAUtils.h"
#include <vector>
#include "llvm/Support/FormatVariadic.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include <cstdint>
using namespace z3;
using namespace std;
using namespace llvm;

int8_t truthTable[15][4] = {
    {0, 0, 0, 1},   // x & y
    {0, 0, 1, 0},   // x & ~y
    {0, 0, 1, 1},   // x
    {0, 1, 0, 0},   // ~x & y
    {0, 1, 0, 1},   // y
    {0, 1, 1, 0},   // x ^ y
    {0, 1, 1, 1},   // x | y
    {1, 0, 0, 0},   // ~(x | y)
    {1, 0, 0, 1},   // ~(x ^ y)
    {1, 0, 1, 0},   // ~y
    {1, 0, 1, 1},   // x | ~y
    {1, 1, 0, 0},   // ~x
    {1, 1, 0, 1},   // ~x | y
    {1, 1, 1, 0},   // ~(x & y)
    {1, 1, 1, 1},   // -1
};

int64_t* llvm::generateLinearMBA(int termsNumber){
    int* exprSelector = new int[termsNumber];
    while(true){
        context c;
        vector<expr> params;
        solver s(c);
        for(int i = 0;i < termsNumber;i ++){
            string paramName = formatv("a{0:d}", i);
            params.push_back(c.int_const(paramName.c_str()));
        }
        for(int i = 0;i < termsNumber;i ++){
            exprSelector[i] = rand() % 15;
        }
        for(int i = 0;i < 4;i ++){
            expr equ = c.int_val(0);
            for(int j = 0;j < termsNumber;j ++){
                equ = equ + params[j] * truthTable[exprSelector[j]][i];
            }
            s.add(equ == 0);
        }
        expr notZeroCond = c.bool_val(false);
        // a1 != 0 || a2 != 0 || ... || an != 0 
        for(int i = 0;i < termsNumber;i ++){
            notZeroCond = notZeroCond || (params[i] != 0);
        }
        s.add(notZeroCond);
        if(s.check() != sat){
            continue;
        }
        model m = s.get_model();
        int64_t *terms = new int64_t[15];
        fill_n(terms, 15, 0);
        for(int i = 0;i < termsNumber;i ++){
            terms[exprSelector[i]] += m.eval(params[i]).get_numeral_int64();
        }
        // reject if all params are 0
        bool all_zero = true;
        for(int i = 0;i < 15;i ++){
            if(terms[i] != 0) all_zero = false;
        }
        if(all_zero){
            delete[] terms;
            continue;
        }
        return terms;
    }
}

Value* llvm::insertLinearMBA(int64_t *params, BinaryOperator *insertBefore){
    IRBuilder<> builder(insertBefore->getContext());
    builder.SetInsertPoint(insertBefore);
    Value *x = insertBefore->getOperand(0);
    Value *y = insertBefore->getOperand(1);
    Value *mbaExpr = builder.CreateAlloca(x->getType());
    builder.CreateStore(ConstantInt::get(x->getType(), 0), mbaExpr);
    mbaExpr = builder.CreateLoad(mbaExpr);
    Value *boolExpr, *term;
    for(int i = 0;i < 15;i ++){
        if(!params[i]) continue;
        // x & y
        if(i == 0) boolExpr = builder.CreateAnd(x, y);
        // x & ~y
        else if(i == 1) boolExpr = builder.CreateAnd(x, builder.CreateNot(y));
        // x
        else if(i == 2) boolExpr = x;
        // ~x & y
        else if(i == 3) boolExpr = builder.CreateAnd(builder.CreateNot(x), y);
        // y
        else if(i == 4) boolExpr = y;
        // x ^ y
        else if(i == 5) boolExpr = builder.CreateXor(x, y);
        // x | y
        else if(i == 6) boolExpr = builder.CreateOr(x, y);
        // ~(x | y)
        else if(i == 7) boolExpr = builder.CreateNot(builder.CreateOr(x, y));
        // ~(x ^ y)
        else if(i == 8) boolExpr = builder.CreateNot(builder.CreateXor(x, y));
        // ~y
        else if(i == 9) boolExpr = builder.CreateNot(y);
        // x | ~y
        else if(i == 10) boolExpr = builder.CreateOr(x, builder.CreateNot(y));
        // ~x
        else if(i == 11) boolExpr = builder.CreateNot(x);
        // ~x | y
        else if(i == 12) boolExpr = builder.CreateOr(builder.CreateNot(x), y);
        // ~(x & y)
        else if(i == 13) boolExpr = builder.CreateNot(builder.CreateAnd(x, y));
        // -1
        else if(i == 14) boolExpr = ConstantInt::get(x->getType(), -1);
        term = builder.CreateMul(ConstantInt::get(x->getType(), params[i]), boolExpr);
        mbaExpr = builder.CreateAdd(mbaExpr, term);
    }
    return mbaExpr;
}

uint64_t inverse(uint64_t n, IntegerType *type){
    context c;
    solver s(c);
    expr a = c.bv_val(n, type->getBitWidth());
    expr a_inv = c.bv_const("a_inv", type->getBitWidth());
    s.add(a * a_inv == 1);
    s.add(a_inv != 0);
    s.check();
    model m = s.get_model();
    return m.eval(a_inv).get_numeral_uint64();
}


void generateUnivariatePoly(uint64_t *a, uint64_t *b, IntegerType *type){
    uint64_t a0, a1, b0, b1, a1_inv;
    a0 = cryptoutils->get_uint64_t(), a1 = cryptoutils->get_uint64_t() | 1;

    // Calculate a1_inv 
    a1_inv = inverse(a1, type);

    // Calculate b1
    b1 = a1_inv;

    // Calculate b0
    b0 = -(b1 * a0);

    a[0] = a0, a[1] = a1, b[0] = b0, b[1] = b1;
}

Value* llvm::insertPolynomialMBA(Value *linearMBAExpr, BinaryOperator *insertBefore){
    IRBuilder<> builder(insertBefore->getContext());
    builder.SetInsertPoint(insertBefore);
    Type *operandType = insertBefore->getOperand(0)->getType();
    uint32_t bitWidth = operandType->getIntegerBitWidth();
    uint64_t a[2], b[2];
    generateUnivariatePoly(a, b, cast<IntegerType>(operandType));
    Value *expr;
    expr = builder.CreateMul(ConstantInt::get(operandType, b[1]), linearMBAExpr);
    expr = builder.CreateAdd(expr, ConstantInt::get(operandType, b[0]));
    expr = builder.CreateMul(ConstantInt::get(operandType, a[1]), expr);
    expr = builder.CreateAdd(expr, ConstantInt::get(operandType, a[0]));
    return expr;
}