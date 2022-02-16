clang_path="../build/bin/"

cd obfu-examples
rm -f build/*

debug(){
    echo -e "\033[32m[*] Test obfuscation with flag '$1' \033[0m"
    out="build/$2.out"
    ${clang_path}clang++ $1 src/TestProgram-2.cpp -o $out
    du -b $out
    ./$out flag{s1mpl3_11vm_d3m0}
}

debug "" "orig"

# Test the TrapAngr pass
debug "-mllvm -rcf" "rcf"