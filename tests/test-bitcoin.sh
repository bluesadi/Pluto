CXX=`pwd`/install/bin/clang++
cd tests/bitcoin
./autogen.sh
./configure CXX=$CXX CXXFLAGS="-mllvm -passes=hlw,fla" 
make clean
make
make check