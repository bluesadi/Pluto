#include "Eigen/Dense"
#include "llvm/Transforms/Obfuscation/MBAUtils.h"
#include "llvm/Support/FormatVariadic.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include <algorithm>
#include <vector>
#include <cstdint>
using namespace Eigen;
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

int64_t* llvm::generateLinearMBA(int exprNumber){
    int* exprSelector = new int[exprNumber];
    int64_t *coeffs = new int64_t[15];
    while(true){
        std::fill_n(coeffs, 15, 0);
        for(int i = 0;i < exprNumber;i ++){
            exprSelector[i] = rand() % 15;
        }
        MatrixXd A(4, exprNumber);
        VectorXd b(4);
        VectorXd X;
        b << 0, 0, 0, 0;
        for(int i = 0;i < exprNumber;i ++){
            for(int j = 0;j < 4;j ++){
                A(j, i) = truthTable[exprSelector[i]][j];
            }
        }
        X = A.fullPivLu().kernel().col(0);
        // reject if coeffs contain non-integer or are all zero
        bool reject = false;
        for(int i = 0;i < exprNumber;i ++){
            coeffs[exprSelector[i]] += X[i];
            if(std::abs(X[i] - (int64_t)X[i]) > 1e-5){
                reject = true;
                break;
            }
        }
        if(reject) continue;
        reject = true;
        for(int i = 0;i < 15;i ++){
            if(coeffs[i] != 0) reject = false;
        }
        if(reject) continue;
        delete[] exprSelector;
        return coeffs;
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

// Extended Euclid's Theorem function.
uint64_t exgcd(uint64_t a, uint64_t b, uint64_t& x, uint64_t& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    uint64_t g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

uint64_t inv(uint64_t a, uint64_t p) {
    uint64_t x, y;
    exgcd(a, p, x, y);
    // get the inverse element
    return (x % p + p) % p;
}

uint64_t inverse(uint64_t n, uint32_t bitWidth){
    assert(bitWidth <= 32);
    return inv(n, 1LL << bitWidth);
}


void generateUnivariatePoly(uint64_t *a, uint64_t *b, uint32_t bitWidth){
    uint64_t a0, a1, b0, b1, a1_inv;
    a0 = cryptoutils->get_uint64_t(), a1 = cryptoutils->get_uint64_t() | 1;

    // Calculate a1_inv 
    a1_inv = inverse(a1, bitWidth);

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
    generateUnivariatePoly(a, b, bitWidth);
    // Just for debug
    // uint64_t x = cryptoutils->get_uint64_t();
    // APInt mask = cast<IntegerType>(operandType)->getMask();
    // if(((a[1] * (b[1] * x + b[0]) + a[0]) & mask) != (x & mask)){
    //     assert(false);
    // }
    Value *expr;
    expr = builder.CreateMul(ConstantInt::get(operandType, b[1]), linearMBAExpr);
    expr = builder.CreateAdd(expr, ConstantInt::get(operandType, b[0]));
    expr = builder.CreateMul(ConstantInt::get(operandType, a[1]), expr);
    expr = builder.CreateAdd(expr, ConstantInt::get(operandType, a[0]));
    return expr;
}