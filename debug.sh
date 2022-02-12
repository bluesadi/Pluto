clang_path="../build/bin/"

cd obfu-examples
rm -f build/*

test(){
    echo -e "\033[32m[*] Test obfuscation with flag '$1' \033[0m"
    out="build/$2.out"
    ${clang_path}clang++ $1 src/TestProgram.cpp src/AES.cpp -o $out
    du -b $out
    ./$out flag{s1mpl3_11vm_d3m0}
    if [ $? -eq 0 ]
    then
        echo -e "\033[32m[*] Test pass \033[0m\n"
    else
        echo -e "\033[31m[*] Test failure \033[0m\n"
    fi
}

test2(){
    echo -e "\033[32m[*] Test obfuscation with flag '$1' \033[0m"
    out="build/$2.out"
    ${clang_path}clang++ $1 src/TestProgram-2.cpp -o $out
    du -b $out
    ./$out flag{s1mpl3_11vm_d3m0}
}

test2 "" "orig"

# Test the TrapAngr pass
test2 "-mllvm -trap-angr" "trap-angr"