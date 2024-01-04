cd tests/tiny-AES-c
../../install/bin/clang -O3 -flto -fuse-ld=lld -mllvm -passes=mba,sub,bcf,fla,gle -Xlinker -mllvm -Xlinker -passes=hlw,idc test.c aes.c -o test.elf
./test.elf