export CC=`pwd`/build/bin/clang
export CFLAGS="-O2 -mllvm -$1"

cd test/secp256k1
make clean
./autogen.sh
./configure
make -j
make check