cd ./Transforms/build
cmake ..
make
cd ../../Test
clang -S -emit-llvm TestProgram.cpp -o TestProgram.ll
opt -load ../Transforms/build/ConstantSubstitution/LLVMConstantSubstitution.so -sub -obfu_time 1 -S TestProgram.ll -o TestProgram_opt.ll
clang TestProgram_opt.ll -o TestProgram