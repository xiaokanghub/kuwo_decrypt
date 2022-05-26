// kuwoDec.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <inttypes.h>
#include <stdlib.h>
#include "b64.h"

typedef unsigned char byte;
uint64_t f3407d[] = { 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000, 0x2000, 0x4000, 0x8000, 0x10000, 0x20000, 0x40000, 0x80000, 0x100000, 0x200000, 0x400000, 0x800000, 0x1000000, 0x2000000, 0x4000000, 0x8000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000, 0x100000000, 0x200000000, 0x400000000, 0x800000000, 0x1000000000, 0x2000000000, 0x4000000000, 0x8000000000, 0x10000000000, 0x20000000000, 0x40000000000, 0x80000000000, 0x100000000000, 0x200000000000, 0x400000000000, 0x800000000000, 0x1000000000000, 0x2000000000000, 0x4000000000000, 0x8000000000000, 0x10000000000000, 0x20000000000000, 0x40000000000000, 0x80000000000000, 0x100000000000000, 0x200000000000000, 0x400000000000000, 0x800000000000000, 0x1000000000000000, 0x2000000000000000, 0x4000000000000000, 0x8000000000000000 };
int f3408e[] = { 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7, 56, 48, 40, 32, 24, 16, 8, 0, 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6 };

int f3409f[] = { 31, 0, 1, 2, 3, 4, -1, -1, 3, 4, 5, 6, 7, 8, -1, -1, 7, 8, 9, 10, 11, 12, -1, -1, 11, 12, 13, 14, 15, 16, -1, -1, 15, 16, 17, 18, 19, 20, -1, -1, 19, 20, 21, 22, 23, 24, -1, -1, 23, 24, 25, 26, 27, 28, -1, -1, 27, 28, 29, 30, 31, 30, -1, -1 };

char f3410g[8][64] = {
    {14, 4, 3, 15, 2, 13, 5, 3, 13, 14, 6, 9, 11, 2, 0, 5, 4, 1, 10, 12, 15, 6, 9, 10, 1, 8, 12, 7, 8, 11, 7, 0, 0, 15, 10, 5, 14, 4, 9, 10, 7, 8, 12, 3, 13, 1, 3, 6, 15, 12, 6, 11, 2, 9, 5, 0, 4, 2, 11, 14, 1, 7, 8, 13},
    {15, 0, 9, 5, 6, 10, 12, 9, 8, 7, 2, 12, 3, 13, 5, 2, 1, 14, 7, 8, 11, 4, 0, 3, 14, 11, 13, 6, 4, 1, 10, 15, 3, 13, 12, 11, 15, 3, 6, 0, 4, 10, 1, 7, 8, 4, 11, 14, 13, 8, 0, 6, 2, 15, 9, 5, 7, 1, 10, 12, 14, 2, 5, 9},
    {10, 13, 1, 11, 6, 8, 11, 5, 9, 4, 12, 2, 15, 3, 2, 14, 0, 6, 13, 1, 3, 15, 4, 10, 14, 9, 7, 12, 5, 0, 8, 7, 13, 1, 2, 4, 3, 6, 12, 11, 0, 13, 5, 14, 6, 8, 15, 2, 7, 10, 8, 15, 4, 9, 11, 5, 9, 0, 14, 3, 10, 7, 1, 12},
    {7, 10, 1, 15, 0, 12, 11, 5, 14, 9, 8, 3, 9, 7, 4, 8, 13, 6, 2, 1, 6, 11, 12, 2, 3, 0, 5, 14, 10, 13, 15, 4, 13, 3, 4, 9, 6, 10, 1, 12, 11, 0, 2, 5, 0, 13, 14, 2, 8, 15, 7, 4, 15, 1, 10, 7, 5, 6, 12, 11, 3, 8, 9, 14},
    {2, 4, 8, 15, 7, 10, 13, 6, 4, 1, 3, 12, 11, 7, 14, 0, 12, 2, 5, 9, 10, 13, 0, 3, 1, 11, 15, 5, 6, 8, 9, 14, 14, 11, 5, 6, 4, 1, 3, 10, 2, 12, 15, 0, 13, 2, 8, 5, 11, 8, 0, 15, 7, 14, 9, 4, 12, 7, 10, 9, 1, 13, 6, 3},
    {12, 9, 0, 7, 9, 2, 14, 1, 10, 15, 3, 4, 6, 12, 5, 11, 1, 14, 13, 0, 2, 8, 7, 13, 15, 5, 4, 10, 8, 3, 11, 6, 10, 4, 6, 11, 7, 9, 0, 6, 4, 2, 13, 1, 9, 15, 3, 8, 15, 3, 1, 14, 12, 5, 11, 0, 2, 12, 14, 7, 5, 10, 8, 13},
    {4, 1, 3, 10, 15, 12, 5, 0, 2, 11, 9, 6, 8, 7, 6, 9, 11, 4, 12, 15, 0, 3, 10, 5, 14, 13, 7, 8, 13, 14, 1, 2, 13, 6, 14, 9, 4, 1, 2, 14, 11, 13, 5, 0, 1, 10, 8, 3, 0, 11, 3, 5, 9, 4, 15, 2, 7, 8, 12, 15, 10, 7, 6, 12},
    {13, 7, 10, 0, 6, 9, 5, 15, 8, 4, 3, 10, 11, 14, 12, 5, 2, 11, 9, 6, 15, 12, 0, 3, 4, 1, 14, 13, 1, 2, 7, 8, 1, 2, 12, 15, 10, 4, 0, 3, 13, 14, 6, 9, 7, 8, 9, 6, 15, 1, 5, 12, 3, 10, 14, 5, 8, 7, 11, 0, 4, 13, 2, 11}
};
int h[] = { 15, 6, 19, 20, 28, 11, 27, 16, 0, 14, 22, 25, 4, 17, 30, 9, 1, 7, 23, 13, 31, 26, 2, 8, 18, 12, 29, 5, 21, 10, 3, 24 };
int i[] = { 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25, 32, 0, 40, 8, 48, 16, 56, 24 };
int j[] = { 56, 48, 40, 32, 24, 16, 8, 0, 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 60, 52, 44, 36, 28, 20, 12, 4, 27, 19, 11, 3 };
int k[] = { 13, 16, 10, 23, 0, 4, -1, -1, 2, 27, 14, 5, 20, 9, -1, -1, 22, 18, 11, 3, 25, 7, -1, -1, 15, 6, 26, 19, 12, 1, -1, -1, 40, 51, 30, 36, 46, 54, -1, -1, 29, 39, 50, 44, 32, 47, -1, -1, 43, 48, 38, 55, 33, 52, -1, -1, 45, 41, 49, 35, 28, 31, -1, -1 };
int l[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
long m[] = { 0, 1048577, 3145731 };
int n = 0;
int o = 1;
uint64_t p = 0;
long q;
uint64_t r;
int s[2] = { 0 };
char t[8] = { 0 };
int u;
int v;
int w;

byte f4714c[128] = { 0 };
byte f4713b[64] = { 0 };


uint64_t permute(int iArr[], int i2, uint64_t j2);
void create_subkeys(uint64_t j2, uint64_t jArr[], int i2);
uint64_t encode_block(uint64_t jArr[], uint64_t j2);
int decrypt(byte bArr[], byte bArr2[], byte decData[]);

void init() {
    char c2 = 'A';
    int i = 0;
    while (c2 <= 'Z') {
        f4713b[i] = c2;
        c2 = (char)(c2 + 1);
        i++;
    }
    char c3 = 'a';
    while (c3 <= 'z') {
        f4713b[i] = c3;
        c3 = (char)(c3 + 1);
        i++;
    }
    char c4 = '0';
    while (c4 <= '9') {
        f4713b[i] = c4;
        c4 = (char)(c4 + 1);
        i++;
    }
    f4713b[i] = '+';
    f4713b[i + 1] = '/';
    for (int i2 = 0; i2 < 128; i2++) {
        f4714c[i2] = -1;
    }
    for (int i3 = 0; i3 < 64; i3++) {
        f4714c[f4713b[i3]] = (byte)i3;
    }


}

byte *b64Decode(char cArr[]) {
    int i;
    char c2;
    int i2;
    int length = strlen(cArr);
    if (length % 4 == 0) {
        while (length > 0 && cArr[length - 1] == '=') {
            length--;
        }
        int i3 = (length * 3) / 4;
        //byte[] bArr = new byte[i3];
        byte* bArr = (byte*)malloc(i3);
        if (bArr == NULL) {
            exit;
        }
        memset(bArr, 0, i3);
        int i4 = 0;
        for (int i5 = 0; i5 < length; i5 = i) {
            int i6 = i5 + 1;
            char c3 = cArr[i5];
            int i7 = i6 + 1;
            char c4 = cArr[i6];
            char c5 = 'A';
            if (i7 < length) {
                i = i7 + 1;
                c2 = cArr[i7];
            }
            else {
                i = i7;
                c2 = 'A';
            }
            if (i < length) {
                int i8 = i + 1;
                char c6 = cArr[i];
                i = i8;
                c5 = c6;
            }
            if (c3 > 127 || c4 > 127 || c2 > 127 || c5 > 127) {
                printf("Illegal character in Base64 encoded data.");
            }
            byte b2 = f4714c[c3];
            byte b3 = f4714c[c4];
            byte b4 = f4714c[c2];
            byte b5 = f4714c[c5];
            if (b2 < 0 || b3 < 0 || b4 < 0 || b5 < 0) {
                printf("Illegal character in Base64 encoded data.");
            }
            int i9 = (b2 << 2) | (b3 >> 4);
            int i10 = ((b3 & 15) << 4) | (b4 >> 2);
            int i11 = ((b4 & 3) << 6) | b5;
            int i12 = i4 + 1;
            bArr[i4] = (byte)i9;
            if (i12 < i3) {
                i2 = i12 + 1;
                bArr[i12] = (byte)i10;
            }
            else {
                i2 = i12;
            }
            if (i2 < i3) {
                i4 = i2 + 1;
                bArr[i2] = (byte)i11;
            }
            else {
                i4 = i2;
            }
        }
        return bArr;
    }


}

uint64_t permute(int iArr[], int i2, uint64_t j2) {
    uint64_t j3 = 0;
    uint64_t jArr[512] = {0};
    for (int i3 = 0; i3 < i2; i3++) {
        if (iArr[i3] >= 0) {
            //long jArr[]  = f3407d;
            memcpy(jArr, f3407d, 512);
            if ((jArr[iArr[i3]] & j2) != 0) {
                //printf("%d\n", i3);
                j3 |= jArr[i3];
                //printf("%d=%I64u\n", i3, j3);
            }
        }
    }
    return j3;
}

void create_subkeys(uint64_t j2, uint64_t jArr[], int i2) {
    uint64_t a2 = permute(j, 56, j2);
    int jArr2[3] = {0};
    int iArr[16] = {0};
    for (int i3 = 0; i3 < 16; i3++) {
        //long jArr2[] = m;
        memcpy(jArr2, m, 12);
        //int iArr[] = l;
        memcpy(iArr, l, 64);
        //printf("%I64u\n", a2);
        a2 = ((a2 & (~jArr2[iArr[i3]])) >> iArr[i3]) | ((jArr2[iArr[i3]] & a2) << (28 - iArr[i3]));
        //printf("%I64u\n", a2);
         jArr[i3] = permute(k, 64, a2);
        //printf("%I64u\n", jArr[i3]);
    }
    if (i2 == 1) {
        for (int i4 = 0; i4 < 8; i4++) {
            uint64_t j3 = jArr[i4];
            int i5 = 15 - i4;
            jArr[i4] = jArr[i5];
            jArr[i5] = j3;
        }
    }
}

uint64_t encode_block(uint64_t jArr[], uint64_t j2) {
    p = permute(f3408e, 64, j2);
    int iArr[2] = {0};
    memcpy(iArr, s, 8);
    uint64_t j3 = p;
    iArr[0] = (int)(j3 & 4294967295L);
    iArr[1] = (int)((j3 & -4294967296L) >> 32);
    memcpy(s, iArr, 8);
    for (int i2 = 0; i2 < 16; i2++) {
        r = (uint64_t)s[1];
        r = permute(f3409f, 64, r);
        r ^= jArr[i2];
        for (int i3 = 0; i3 < 8; i3++) {
            t[i3] = (byte)((int)(255 & (r >> (i3 * 8))));
        }
        u = 0;
        int i4 = 7;
        while (true) {
            w = i4;
            int i5 = w;
            if (i5 < 0) {
                break;
            }
            u <<= 4;
            u |= f3410g[i5][t[i5]];
            i4 = i5 - 1;
        }
        r = (uint64_t)u;
        r = permute(h, 32, r);
        int iArr2[2] = {0};
        memcpy(iArr2, s, 8);
        q = (uint64_t)iArr2[0];
        iArr2[0] = iArr2[1];
        iArr2[1] = (int)(q ^ r);
        memcpy(s, iArr2, 8);
    }
    int iArr3[2] = {0};
    memcpy(iArr3, s, 8);
    v = iArr3[0];
    iArr3[0] = iArr3[1];
    iArr3[1] = v;
    p = ((((uint64_t)iArr3[1]) << 32) & -4294967296L) | (4294967295L & ((long)iArr3[0]));
    p = permute(i, 64, p);
    return p;
}


int decrypt(byte bArr[], byte bArr2[], byte decData[]) {
    //byte bArr3[] = {0};
    int length = strlen((const char*)bArr)*4;
    int length2 = strlen((const char*)bArr2);
    uint64_t jArr[16] = { 0 };
    uint64_t j2 = 0;
    for (int i2 = 0; i2 < 8; i2++) {
        j2 |= ((uint64_t)bArr2[i2]) << (i2 * 8);
    }
    for (int i3 = 0; i3 < 16; i3++) {
        jArr[i3] = 0;
    }
    create_subkeys(j2, jArr, 1);
    int i4 = length / 8;
    uint64_t *jArr2 = (uint64_t*)malloc(sizeof(uint64_t) * i4);
    
    if (jArr2 == NULL) {
        return 1;
    }
    memset(jArr2, 0, sizeof(uint64_t) * i4);
    //uint64_t jArr2[1024] = { 0 };
    //memcpy(jArr2, 0, i4);
    for (int i5 = 0; i5 < i4; i5++) {
        for (int i6 = 0; i6 < 8; i6++) {
            jArr2[i5] = jArr2[i5] | (((uint64_t)(bArr[(i5 * 8) + i6] & 255)) << (i6 * 8));
        }
    }
    //long[] jArr3 = new long[i4];
    uint64_t *jArr3 = (uint64_t*)malloc(sizeof(uint64_t)*i4);
    
    if (jArr3 == NULL) {
        return 1;
    }
    memset(jArr3, 0, sizeof(uint64_t) * i4);
    //uint64_t jArr3[1024] = { 0 };
    //memcpy(jArr3, 0, i4);
    for (int i7 = 0; i7 < i4; i7++) {
        jArr3[i7] = encode_block(jArr, jArr2[i7]);
    }
    free(jArr2);
    //bArr3 = new byte[(i4 * 8)];
    //memcpy(bArr3, 0, 35*8);
    for (int i8 = 0; i8 < i4; i8++) {
        for (int i9 = 0; i9 < 8; i9++) {
            decData[(i8 * 8) + i9] = (byte)((int)(255 & (jArr3[i8] >> (i9 * 8))));
        }
    }
    free(jArr3);   
    return 0;
}

int main()
{
    
    unsigned char* key = (unsigned char*)"kwks&@69";
    const char *encData = "Sy1Jlx5q/p4fi36+xHQg5OYn+BlbKjAk14xTvFn//Gx75jE6fBfkwkc+05OaGXLCxeionnSus+kcjOWpnXPmeT08HGZ/E1OytmJRoTx3AqdZKMxwev516Jknlyt/kXhKaG1lB0+iFSZQUwebv59loiUdoRHx1vRhzHfSncvyegOD6g3Sc3ISHM1ZyJYsUATyNUQGO5e6HRuJh2VoYFMb8Oa8Wk/T/Y3/Z02WGpC3/odbkud/4+TGbEJUtA/R2oHWq6N35tQXisSRZLAzqwT6Wg1r7dPZbBCdIfz8YmmUBmYk6rfNvKF/MQ==";
    //init();
    unsigned char* b64dec = b64_decode(encData, strlen(encData));
    //unsigned char* b64dec = b64Decode((char *)encData);
    byte *decData = (byte*)malloc(strlen((const char*)b64dec) * 4);
    if (decData == NULL) {
        return 1;
    }
    memset(decData, 0, strlen((const char*)b64dec) * 4);
    decrypt(b64dec, key, decData);
    printf("%s\n", (char*)decData);

    free(decData);
   
    return 0;


}

