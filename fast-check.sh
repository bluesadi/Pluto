CXXFLAGS="-O2 -mllvm -$1"

cd test/aes
rm -f TestProgram.out
../../build/bin/clang++ AES.cpp TestProgram.cpp $CXXFLAGS -o TestProgram.out
./TestProgram.out flag{s1mpl3_11vm_d3m0} 