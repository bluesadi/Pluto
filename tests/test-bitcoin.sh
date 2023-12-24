cd tests/bitcoin
./autogen.sh
./configure CXX=/root/Pluto/install/bin/clang++ CXXFLAGS="-mllvm -passes=hlw,fla" 
make clean
make
make check