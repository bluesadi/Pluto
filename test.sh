cd ./Transforms/build
cmake ..
make
cd ../../Test
clang -S -emit-llvm TestProgram.cpp -o TestProgram.ll
opt -load ../Transforms/build/BogusControlFlow/LLVMBogusControlFlow.so -boguscf -S TestProgram.ll -o TestProgram_opt.ll
clang TestProgram_opt.ll -o TestProgram