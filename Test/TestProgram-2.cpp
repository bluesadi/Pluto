#include <cstdio>
#include <cstring>
#include <cstdlib>
#define BYTE unsigned char

bool a2b_hex(BYTE *dest, char *src){
    int len = strlen(src);
    for(int i = 0;i < len;i += 2){
        if(src[i] >= 'a' && src[i] <= 'f'){
            dest[i / 2] += (src[i] - 'a' + 10) * 16;
        }else if(src[i] >= '0' && src[i] <= '9'){
            dest[i / 2] += (src[i] - '0') * 16;
        }else{
            return false;
        }
        if(src[i + 1] >= 'a' && src[i + 1] <= 'f'){
            dest[i / 2] += src[i + 1] - 'a' + 10;
        }else if(src[i] >= '0' && src[i + 1] <= '9'){
            dest[i / 2] += src[i + 1] - '0';
        }else{
            return false;
        }
    }
    return true;
}

int32_t T_Box[16] = {52, 22, 33, 13, 1, 50, 65, 67, 20, 18, 9, 72, 41, 14, 70, 96};
int32_t M[16] = {4550,9560,14993,21490,10754,9076,13153,12068,22043,16418,32364,37064,13211,9310,16231,24974};
char *input;

// 1781631d2793a5472c241c41f37997ac
int main(int argc, char *argv[]){
    printf("Welcome to LLVM world...\n");
    if(argc <= 1){
        printf("Input your flag as an argument.\n");
        return 0;
    }
    input = argv[1];
    if(strlen(input) != 32){
        printf("Wrong length!\n");
        exit(0);
    }
    BYTE hex[100] = {0};
    if(!a2b_hex(hex, input)){
        printf("Wrong format!\n");
        exit(0);
    }
    //第一轮：仿射加密
    BYTE x[100] = {0};
    for(int i = 0;i < 16;i ++){
        x[i] = (11 * hex[i] + 6) % 256; 
    }
    //第二轮：矩阵相乘
    // y = [
    //        [4550 9560 14993 21490]
    //        [10754 9076 13153 12068] 
    //        [22043 16418 32364 37064] 
    //        [13211 9310 16231 24974]
    //     ]
    int y[16] = {0};
    for(int i = 0;i < 4;i ++){
        for(int j = 0;j < 4;j ++){
            for(int k = 0;k < 4;k ++){
                y[i * 4 + j] += x[i * 4 + k] * T_Box[k * 4 + j];
            }
        }
    }
    if(!memcmp(y, M, 16 * sizeof(int32_t))){
        printf("Right!\n");
    }else{
        printf("Wrong!\n");
    }
}