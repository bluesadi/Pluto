if [ ! -d "Build" ]; then
    mkdir Build
fi
cd ./Build
cmake ../Transforms
make
cd ../Test

# 未混淆的ELF文件
clang -S -emit-llvm TestProgram.cpp -o IR/TestProgram_orig.ll
clang IR/TestProgram_orig.ll -o Bin/TestProgram_orig
echo -e "\n\033[32m> Test case on original binary <\033[0m"
./Bin/TestProgram_orig flag{s1mpl3_11vm_d3m0}

# 基本块分割
opt -load ../Build/LLVMObfuscator.so -split -split_num 3 -S IR/TestProgram_orig.ll -o IR/TestProgram_split.ll
clang IR/TestProgram_split.ll -o Bin/TestProgram_split

# 控制流平坦化
opt -lowerswitch -S IR/TestProgram_orig.ll -o IR/TestProgram_lowerswitch.ll
opt -load ../Build/LLVMObfuscator.so -fla -split_num 3 -S IR/TestProgram_lowerswitch.ll -o IR/TestProgram_fla.ll
clang IR/TestProgram_fla.ll -o Bin/TestProgram_fla
echo -e "\n\033[32m> Test case on Flattening <\033[0m"
./Bin/TestProgram_fla flag{s1mpl3_11vm_d3m0}

# 虚假控制流
opt -load ../Build/LLVMObfuscator.so -bcf -bcf_loop 2 -split_num 3 -S IR/TestProgram_orig.ll -o IR/TestProgram_bcf.ll
clang IR/TestProgram_bcf.ll -o Bin/TestProgram_bcf
echo -e "\n\033[32m> Test case on BogusControlFlow <\033[0m"
./Bin/TestProgram_bcf flag{s1mpl3_11vm_d3m0}

# 指令替换
opt -load ../Build/LLVMObfuscator.so -sub -sub_loop 2 -S IR/TestProgram_orig.ll -o IR/TestProgram_sub.ll
clang IR/TestProgram_sub.ll -o Bin/TestProgram_sub
echo -e "\n\033[32m> Test case on Substitution <\033[0m"
./Bin/TestProgram_sub flag{s1mpl3_11vm_d3m0}

# 随机控制流
opt -load ../Build/LLVMObfuscator.so -rcf -S IR/TestProgram_orig.ll -o IR/TestProgram_rcf.ll
llc -filetype=obj -mattr=+rdrnd IR/TestProgram_rcf.ll -o Bin/TestProgram_rcf.o
clang Bin/TestProgram_rcf.o -o Bin/TestProgram_rcf
echo -e "\n\033[32m> Test case on RandomControlFlow <\033[0m"
./Bin/TestProgram_rcf flag{s1mpl3_11vm_d3m0}

# 常量替换
opt -load ../Build/LLVMObfuscator.so -csub -csub_loop 2 -S IR/TestProgram_orig.ll -o IR/TestProgram_csub.ll
clang IR/TestProgram_csub.ll -o Bin/TestProgram_csub
echo -e "\n\033[32m> Test case on ConstantSubstitution <\033[0m"
./Bin/TestProgram_csub flag{s1mpl3_11vm_d3m0}