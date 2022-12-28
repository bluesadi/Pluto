#!/bin/sh

CXXFLAGS=""

for arg in "$@"; do
    CXXFLAGS="-mllvm -$arg $CXXFLAGS"
done

cd test/aes
rm -f test
../../install/bin/clang++ aes.cpp test.cpp $CXXFLAGS -o test
./test flag{s1mpl3_11vm_d3m0} 