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

# Test the Flattening pass
test "-mllvm -fla -mllvm -split-num=3" "fla"

# Test the BogusControlFlow pass
test "-mllvm -bcf -mllvm -bcf-times=2 -mllvm -split-num=3" "bcf"

# Test the Substitution pass
test "-mllvm -sub -mllvm -sub-times=2" "sub"

# Test the GlobalsEncryption pass
test "-mllvm -gle -mllvm -gle-times=2" "gle"

# Test the StringEncryption pass
test "-mllvm -gle -mllvm -gle-times=2 -mllvm -onlystr" "ste"

# Test the VariableSubstitution pass
test "-mllvm -vsb -mllvm -vsb-times=2" "vsb"