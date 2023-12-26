cd tests/openssl
CC=../../install/bin/clang CFLAGS="-mllvm -passes=hlw,idc,mba,fla,sub" ./Configure
make -j`nproc` tests