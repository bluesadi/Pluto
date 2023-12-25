CC=`pwd`/install/bin/clang
CXX=`pwd`/install/bin/clang++
FLAGS="-mllvm -passes=hlw,fla,mba"
cd tests/bitcoin
./autogen.sh
./configure CC=$CC CXX=$CXX CXXFLAGS=$FLAGS
make clean
make -j`nproc`
make check