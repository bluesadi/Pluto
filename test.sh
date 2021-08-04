cd ./Build
cmake ../Transforms
make
cd ../Test
# 未混淆的ELF文件
clang -S -emit-llvm TestProgram.cpp -o IR/TestProgram_orig.ll
clang IR/TestProgram_orig.ll -o Bin/TestProgram_orig
# 基本块分割
opt -load ../Build/LLVMObfuscator.so -split -split_num 3 -S IR/TestProgram_orig.ll -o IR/TestProgram_split.ll
clang IR/TestProgram_split.ll -o Bin/TestProgram_split
# 控制流平坦化
opt -lowerswitch -S IR/TestProgram_orig.ll -o IR/TestProgram_lowerswitch.ll
opt -load ../Build/LLVMObfuscator.so -fla -split_num 3 -S IR/TestProgram_lowerswitch.ll -o IR/TestProgram_fla.ll
clang IR/TestProgram_fla.ll -o Bin/TestProgram_fla
# 虚假控制流
opt -load ../Build/LLVMObfuscator.so -bcf -bcf_loop 2 -split_num 3 -S IR/TestProgram_orig.ll -o IR/TestProgram_bcf.ll
clang IR/TestProgram_bcf.ll -o Bin/TestProgram_bcf
# 指令替换
opt -load ../Build/LLVMObfuscator.so -sub -sub_loop 2  -S IR/TestProgram_orig.ll -o IR/TestProgram_sub.ll
clang IR/TestProgram_sub.ll -o Bin/TestProgram_sub