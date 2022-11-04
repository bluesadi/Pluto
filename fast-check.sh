#!/bin/sh

CXXFLAGS=""

for arg in "$@"; do
    CXXFLAGS="-mllvm -$arg $CXXFLAGS"
done

cd test/aes
rm -f TestProgram.out
../../install/bin/clang++ AES.cpp TestProgram.cpp $CXXFLAGS -o TestProgram.out
./TestProgram.out flag{s1mpl3_11vm_d3m0} 