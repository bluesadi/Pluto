export CC=`pwd`/build/bin/clang
export CFLAGS="-mllvm -gle"

cd test/secp256k1
make clean
./configure
make
make check