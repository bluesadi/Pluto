export CC=`which clang`
export CFLAGS="-mllvm -hlw"
if [ -z $CC ]; then
    echo "Cannot find clang path. Please specify it manually."
    exit 1
fi

cd test/secp256k1
make clean
./configure
make
make check