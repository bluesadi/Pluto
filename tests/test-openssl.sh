cd tests/openssl
CC=../../install/bin/clang CFLAGS="-flto -fuse-ld=lld -O3 -mllvm -passes=mba,fla,sub -Xlinker -mllvm -Xlinker -passes=hlw,idc -Wno-unused-command-line-argument" ./Configure
make -j`nproc` tests