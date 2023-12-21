cd tests/tiny-AES-c
../../install/bin/clang -mllvm -passes=hlw,fla test.c aes.c -o test.elf
./test.elf