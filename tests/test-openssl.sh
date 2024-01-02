cd tests/openssl
CC=../../install/bin/clang CFLAGS="-O0 -mllvm -passes=mba,sub,idc,fla,bcf" ./Configure
make clean
make -j8 tests