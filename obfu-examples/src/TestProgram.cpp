#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "AES.h"

char *input;
char enc[100] = "\xce\x6a\x64\x09\x74\x00\xf7\xf0\x86\x31\x5b\x78\xe3\x05\x6f\xfa\xcf\x31\x00\x45\xff\x19\xdf\xeb\xea\xcc\x33\x97\x26\xce\xbc\xa3"; 

//flag{s1mpl3_11vm_d3m0} 
int main(int argc, char *argv[]){ 
    printf("Welcome to LLVM world...\n");
    input = argv[1];
    printf("Your flag is: %s\n", input);
    AES aes((BYTE*)"1234567812345678", 128);
    int outlen;
    unsigned char *dest = aes.EncryptECB((BYTE*)input, 22, outlen);
    if(strlen(input) == 22 && !memcmp(dest, enc, 32)){ 
        printf("Congratulations~\n"); 
        return 0;
    }else{
        printf("Sorry try again.\n"); 
        return -1;
    }
}