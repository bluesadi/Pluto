#include "aes.h"

AES::AES(BYTE* key, int keyLen){
    this->key = key;
    this->Nb = 4;
    this->Ns = 1;
    switch (keyLen){
        case 128:
            this->Nk = 4;
            this->Nr = 10;
            break;
        case 192:
            this->Nk = 6;
            this->Nr = 12;
            break;
        case 256:
            this->Nk = 8;
            this->Nr = 14;
            break;
        default:
            throw "Incorrect key length";
    }
}

void AES::PrintHex(BYTE *in, int n){
    for(int i = 0;i < n;i ++){
        printf("%02x", in[i]);
    }
    printf("\n");
}

/*
若明文不是分组长度的倍数，用0填充
*/
BYTE* AES::ZeroPadding(BYTE *in, int inLen, int &outLen){
    outLen = inLen % (4 * Nb) == 0 ? inLen : (inLen / (4 * Nb) + 1) * (4 * Nb);
    BYTE *alignIn = new BYTE[outLen];
    memcpy(alignIn, in, inLen);
    memset(alignIn + inLen, 0, outLen - inLen);
    return alignIn;
}

BYTE AES::SubByte(BYTE b){
    return S_BOX[b];
}

void AES::SubWord(BYTE *w){
    for(int i = 0;i < 4;i ++){
        w[i] = SubByte(w[i]);
    }
}

void AES::RotWord(BYTE *w){
    BYTE t = w[0];
    w[0] = w[1];
    w[1] = w[2];
    w[2] = w[3];
    w[3] = t;
}

/*
密钥拓展算法
*/
BYTE* AES::KeyExpansion(){
    WORD *keyExp = new WORD[Nb * (Nr + 1)];
    for(int i = 0;i < Nk;i ++){
        keyExp[i] = ((WORD*)key)[i];
    }
    for(int i = Nk;i < Nb * (Nr + 1);i ++){
        WORD temp = keyExp[i - 1];
        if(i % Nk == 0){
            RotWord((BYTE*)&temp);
            SubWord((BYTE*)&temp);
            temp ^= RCON[i / Nk - 1];
        }else if(Nk == 8 && (i % Nk == 4)){
            SubWord((BYTE*)&temp);
        }
        keyExp[i] = keyExp[i - Nk] ^ temp;
    }
    return (BYTE*)keyExp;
}

/*
添加轮密钥
*/
void AES::AddRoundKey(BYTE **state, BYTE *roundKey){
    for(int i = 0;i < 4;i ++){
        for(int j = 0;j < Nb;j ++){
            state[i][j] ^= roundKey[i + 4 * j];
        }
    }
}

/*
字节替换变换
*/
void AES::SubBytes(BYTE **state){
    for(int i = 0;i < 4;i ++){
        for(int j = 0;j < Nb;j ++){
            state[i][j] = SubByte(state[i][j]);
        }
    }
}

void AES::ShiftRow(BYTE *row, int n){
    BYTE temp[4] = {0};
    for(int i = 0;i < Nb;i ++){
        temp[i] = row[(i + Nb + n) % Nb];
    }
    memcpy(row, temp, Nb);
}

/*
行位移变换
*/
void AES::ShiftRows(BYTE **state){
    for(int i = 0;i < 4;i ++){
        ShiftRow(state[i], i);    
    }
}

BYTE AES::xtime(BYTE b){
    return (b << 1) ^ (((b >> 7) & 1) * 0x1b);
}

BYTE AES::mul(BYTE a, BYTE b){
    BYTE temp = b, result = 0;
    while(a){
        if(a & 1) result ^= temp;
        temp = xtime(temp);
        a >>= 1;
    }    
    return result;
}

void AES::MixSingleColumn(BYTE *column){
    BYTE temp[4] = {0};
    BYTE M[4][4] = {
        {2, 3, 1, 1},
        {1, 2, 3, 1},
        {1, 1, 2, 3},
        {3, 1, 1, 2}
    };
    for(int i = 0;i < 4;i ++){
        for(int j = 0;j < 4;j ++){
            temp[i] ^= mul(M[i][j], column[j]);
        }    
    }
    memcpy(column, temp, 4);
}

/*
列混合变换
*/
void AES::MixColumns(BYTE **state){
    for(int i = 0;i < Nb;i ++){
        BYTE column[4] = {0};
        for(int j = 0;j < 4;j ++){
            column[j] = state[j][i];
        }
        MixSingleColumn(column);
        for(int j = 0;j < 4;j ++){
            state[j][i] = column[j];
        }
    }
}

BYTE* AES::EncryptBlock(BYTE *in, BYTE *roundKeys){
    BYTE *block = new BYTE[4 * Nb];
    BYTE **state = new BYTE*[4];
    for(int i = 0;i < 4;i ++){
        state[i] = block + i * Nb;
    }
    for(int i = 0;i < 4;i ++){
        for(int j = 0;j < Nb;j ++){
            state[i][j] = in[i + 4 * j];
        }
    }
    AddRoundKey(state, roundKeys);
    for(int round = 1;round < Nr;round ++){
        SubBytes(state);
        ShiftRows(state);
        MixColumns(state);
        AddRoundKey(state, roundKeys + round * 4 * Nb);
        /*if(round == 7){
            printf("n = 8: ");
            PrintHex(block, 4 * Nb);
        }*/
    }
    SubBytes(state);
    ShiftRows(state);
    AddRoundKey(state, roundKeys + Nr * 4 * Nb);
    BYTE *encBlock = new BYTE[4 * Nb];
    for(int i = 0;i < 4;i ++){
        for(int j = 0;j < Nb;j ++){
            encBlock[i + 4 * j] = state[i][j];
        }
    }
    delete[] block;
    return encBlock;
}

void AES::InvSubBytes(BYTE **state){
    for(int i = 0;i < 4;i ++){
        for(int j = 0;j < Nb;j ++){
            state[i][j] = INV_S_BOX[state[i][j]];
        }
    }
}

void AES::InvShiftRows(BYTE **state){
    for(int i = 0;i < 4;i ++){
        ShiftRow(state[i], -i);
    }
}

void AES::InvMixSingleColumn(BYTE *column){
    BYTE temp[4] = {0};
    BYTE M[4][4] = {
        {0x0E, 0x0B, 0x0D, 0x09},
        {0x09, 0x0E, 0x0B, 0x0D},
        {0x0D, 0x09, 0x0E, 0x0B},
        {0x0B, 0x0D, 0x09, 0x0E}
    };
    for(int i = 0;i < 4;i ++){
        for(int j = 0;j < 4;j ++){
            temp[i] ^= mul(M[i][j], column[j]);
        }    
    }
    memcpy(column, temp, 4);
}

void AES::InvMixColumns(BYTE **state){
    for(int i = 0;i < Nb;i ++){
        BYTE column[4] = {0};
        for(int j = 0;j < 4;j ++){
            column[j] = state[j][i];
        }
        InvMixSingleColumn(column);
        for(int j = 0;j < 4;j ++){
            state[j][i] = column[j];
        }
    }
}

BYTE* AES::DecryptBlock(BYTE *in, BYTE *roundKeys){
    BYTE *block = new BYTE[4 * Nb];
    BYTE **state = new BYTE*[4];
    for(int i = 0;i < 4;i ++){
        state[i] = block + i * Nb;
    }
    for(int i = 0;i < 4;i ++){
        for(int j = 0;j < Nb;j ++){
            state[i][j] = in[i + 4 * j];
        }
    }
    AddRoundKey(state, roundKeys + Nr * 4 * Nb);
    for(int round = Nr - 1;round >= 1;round --){
        InvShiftRows(state);
        InvSubBytes(state);
        AddRoundKey(state, roundKeys + round * 4 * Nb);
        InvMixColumns(state);
    }
    InvShiftRows(state);
    InvSubBytes(state);
    AddRoundKey(state, roundKeys);
    BYTE *decBlock = new BYTE[4 * Nb];
    for(int i = 0;i < 4;i ++){
        for(int j = 0;j < Nb;j ++){
            decBlock[i + 4 * j] = state[i][j];
        }
    }
    delete[] block;
    return decBlock;
}

/*
ECB模式，加密
*/
BYTE* AES::EncryptECB(BYTE *in, int inLen, int &outLen){
    BYTE *roundKeys = KeyExpansion();
    BYTE *alignIn = ZeroPadding(in, inLen, outLen);
    BYTE *cipher = new BYTE[outLen];
    for(int i = 0;i < outLen / (4 * Nb);i ++){
        BYTE *encBlock = EncryptBlock(alignIn + i * 4 * Nb, roundKeys);
        memcpy(cipher + i * 4 * Nb, encBlock, 4 * Nb);
        delete[] encBlock;
    }
    delete[] roundKeys;
    delete[] alignIn;
    return cipher;
}

/*
ECB模式，解密
*/
BYTE* AES::DecryptECB(BYTE *in, int inLen){
    BYTE *roundKeys = KeyExpansion();
    BYTE *plain = new BYTE[inLen];
    for(int i = 0;i < inLen / (4 * Nb);i ++){
        BYTE *decBlock = DecryptBlock(in + i * 4 * Nb, roundKeys);
        memcpy(plain + i * 4 * Nb, decBlock, 4 * Nb);
        delete[] decBlock;
    }
    delete[] roundKeys;
    return plain;
}

void AES::XorBlock(BYTE *block, BYTE* bv){
    for(int i = 0;i < 4 * Nb;i ++){
        block[i] ^= bv[i];
    }
}

/*
CBC模式，加密
*/
BYTE* AES::EncryptCBC(BYTE *in, int inLen, BYTE *iv, int &outLen){
    BYTE *roundKeys = KeyExpansion();
    BYTE *alignIn = ZeroPadding(in, inLen, outLen);
    BYTE *cipher = new BYTE[outLen];
    BYTE *bv = new BYTE[4 * Nb];
    memcpy(bv, iv, 4 * Nb);
    for(int i = 0;i < outLen / (4 * Nb);i ++){
        XorBlock(alignIn + i * 4 * Nb, bv);
        BYTE *encBlock = EncryptBlock(alignIn + i * 4 * Nb, roundKeys);
        memcpy(bv, encBlock, 4 * Nb);
        memcpy(cipher + i * 4 * Nb, encBlock, 4 * Nb);
        delete[] encBlock;
    }
    delete[] roundKeys;
    delete[] alignIn;
    delete[] bv;
    return cipher;
}

/*
CBC模式，解密
*/
BYTE* AES::DecryptCBC(BYTE *in, int inLen, BYTE *iv){
    BYTE *roundKeys = KeyExpansion();
    BYTE *plain = new BYTE[inLen];
    BYTE *bv = new BYTE[4 * Nb];
    memcpy(bv, iv, 4 * Nb);
    for(int i = 0;i < inLen / (4 * Nb);i ++){
        BYTE *decBlock = DecryptBlock(in + i * 4 * Nb, roundKeys);
        XorBlock(decBlock, bv);
        memcpy(bv, in + i * 4 * Nb, 4 * Nb);
        memcpy(plain + i * 4 * Nb, decBlock, 4 * Nb);
        delete[] decBlock;
    }
    delete[] roundKeys;
    delete[] bv;
    return plain;
}

void AES::ShiftBV(BYTE *bv, BYTE* padding){
    BYTE *temp = new BYTE[4 * Nb];
    memcpy(temp, bv + 4 * Ns, 4 * Nb - 4 * Ns);
    memcpy(temp + 4 * Nb - 4 * Ns, padding, 4 * Ns);
    memcpy(bv, temp, 4 * Nb);
}

/*
CFB模式，加密
*/
BYTE* AES::EncryptCFB(BYTE *in, int inLen, BYTE *iv, int &outLen){
    BYTE *roundKeys = KeyExpansion();
    BYTE *alignIn = ZeroPadding(in, inLen, outLen);
    BYTE *cipher = new BYTE[outLen];
    BYTE *bv = new BYTE[4 * Nb];
    memcpy(bv, iv, 4 * Nb);
    for(int i = 0;i < outLen / (4 * Ns);i ++){
        BYTE *encBV = EncryptBlock(bv, roundKeys);
        for(int j = 0;j < 4 * Ns;j ++){
            cipher[i * 4 * Ns + j] = alignIn[i * 4 * Ns + j] ^ encBV[j];
        }
        ShiftBV(bv, cipher + i * 4 * Ns);
        delete[] encBV;
    }
    delete[] roundKeys;
    delete[] alignIn;
    delete[] bv;
    return cipher;
}

/*
CFB模式，解密
*/
BYTE* AES::DecryptCFB(BYTE *in, int inLen, BYTE *iv){
    BYTE *roundKeys = KeyExpansion();
    BYTE *plain = new BYTE[inLen];
    BYTE *bv = new BYTE[4 * Nb];
    memcpy(bv, iv, 4 * Nb);
    for(int i = 0;i < inLen / (4 * Ns);i ++){
        BYTE *encBV = EncryptBlock(bv, roundKeys);
        for(int j = 0;j < 4 * Ns;j ++){
            plain[i * 4 * Ns + j] = in[i * 4 * Ns + j] ^ encBV[j];
        }
        ShiftBV(bv, in + i * 4 * Ns);
        delete[] encBV;
    }
    delete[] roundKeys;
    delete[] bv;
    return plain;
}

/*
OFB模式，加密
*/
BYTE* AES::EncryptOFB(BYTE *in, int inLen, BYTE *iv, int &outLen){
    BYTE *roundKeys = KeyExpansion();
    BYTE *alignIn = ZeroPadding(in, inLen, outLen);
    BYTE *cipher = new BYTE[outLen];
    BYTE *bv = new BYTE[4 * Nb];
    memcpy(bv, iv, 4 * Nb);
    for(int i = 0;i < outLen / (4 * Ns);i ++){
        BYTE *encBV = EncryptBlock(bv, roundKeys);
        for(int j = 0;j < 4 * Ns;j ++){
            cipher[i * 4 * Ns + j] = alignIn[i * 4 * Ns + j] ^ encBV[j];
        }
        ShiftBV(bv, encBV);
        delete[] encBV;
    }
    delete[] roundKeys;
    delete[] alignIn;
    delete[] bv;
    return cipher;
}

/*
OFB模式，解密
*/
BYTE* AES::DecryptOFB(BYTE *in, int inLen, BYTE *iv){
    BYTE *roundKeys = KeyExpansion();
    BYTE *plain = new BYTE[inLen];
    BYTE *bv = new BYTE[4 * Nb];
    memcpy(bv, iv, 4 * Nb);
    for(int i = 0;i < inLen / (4 * Ns);i ++){
        BYTE *encBV = EncryptBlock(bv, roundKeys);
        for(int j = 0;j < 4 * Ns;j ++){
            plain[i * 4 * Ns + j] = in[i * 4 * Ns + j] ^ encBV[j];
        }
        ShiftBV(bv, encBV);
        delete[] encBV;
    }
    delete[] roundKeys;
    delete[] bv;
    return plain;
}