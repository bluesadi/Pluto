#include <cstdio>
#include <cstring>

char input[100] = {0};
char enc[100] = "\x86\x8a\x7d\x87\x93\x8b\x4d\x81\x80\x8a\
\x43\x7f\x49\x49\x86\x71\x7f\x62\x53\x69\x28\x9d";

void encrypt(unsigned char *dest, char *src){
    int len = strlen(src);
    for(int i = 0;i < len;i ++){
        dest[i] = (src[i] + (32 - i)) ^ i;
    }
}


//flag{s1mpl3_11vm_d3m0}
int main(){
    printf("Please input your flag: ");
    scanf("%s", input);
    unsigned char dest[100] = {0};
    encrypt(dest, input);
    bool result = strlen(input) == 22 && !strcmp((char*)dest, enc);
    if(result){
        printf("Congratulations~\n");
    }else{
        printf("Sorry try again.\n");
    }
}