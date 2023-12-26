cd tests/tiny-AES-c
../../install/bin/clang -mllvm -passes=hlw,fla,sub,mba test.c aes.c -o test.elf
./test.elf