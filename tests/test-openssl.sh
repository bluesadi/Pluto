cd tests/openssl
CC=../../install/bin/clang CFLAGS="-mllvm -passes=hlw,fla,mba" ./Configure
make -j`nproc` tests