cd tests/tiny-AES-c
../../install/bin/clang -O3 -mllvm -passes=hlw,idc,mba,fla,sub test.c aes.c -o test.elf
./test.elf