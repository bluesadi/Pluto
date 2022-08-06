CXXFLAGS=""

for arg in "$@"; do
    CXXFLAGS="-mllvm -$arg $CXXFLAGS"
done

cd test/aes
rm -f TestProgram.out
../../build/bin/clang++ AES.cpp TestProgram.cpp $CXXFLAGS -o TestProgram.out
# ../../build/bin/clang++ TestProgram.cpp -emit-llvm -S -g -o TestProgram.dbg.ll
# ../../build/bin/clang++ TestProgram.cpp -emit-llvm -S -o TestProgram.ll
./TestProgram.out flag{s1mpl3_11vm_d3m0} 