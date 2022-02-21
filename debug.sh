clang_path="../build/bin/"

cd obfu-examples
rm -f build/*

debug(){
    echo -e "\033[32m[*] Test obfuscation with flag '$1' \033[0m"
    out="build/$2.out"
    ${clang_path}clang++ -emit-llvm -S $1 src/TestProgram-3.cpp -o build/debug.ll
    #${clang_path}clang++ $1 src/TestProgram.cpp src/AES.cpp -o $out.1
    ${clang_path}clang++ $1 src/TestProgram-2.cpp -o $out.2
    ${clang_path}clang++ $1 src/TestProgram-3.cpp -o $out.3
    du -b $out.2
    ./$out.2 flag{s1mpl3_11vm_d3m0}
}

debug "" "orig"

# Test the TrapAngr pass
debug "-mllvm -linear-mba" "linear-mba"