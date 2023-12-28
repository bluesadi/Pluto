cd tests/tiny-AES-c
../../install/bin/clang -O3 -flto -fuse-ld=lld -mllvm -passes=mba,fla,sub -Xlinker -mllvm -Xlinker -passes=hlw,idc test.c aes.c -o test.elf
./test.elf