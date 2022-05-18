// kuwoDec.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <inttypes.h>

typedef unsigned char byte;
//uint64_t f3407d[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296, 8589934592, 17179869184, 34359738368, 68719476736L, 137438953472L, 274877906944L, 549755813888L, 1099511627776L, 2199023255552L, 4398046511104L, 8796093022208L, 17592186044416L, 35184372088832L, 70368744177664L, 140737488355328L, 281474976710656L, 562949953421312L, 1125899906842624L, 2251799813685248L, 4503599627370496L, 9007199254740992L, 18014398509481984L, 36028797018963968L, 72057594037927936L, 144115188075855872L, 288230376151711744L, 576460752303423488L, 1152921504606846976L, 2305843009213693952L, 4611686018427387904L, 0x8000000000000000 };
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

uint64_t permute(int iArr[], int i2, uint64_t j2);
void create_subkeys(uint64_t j2, uint64_t jArr[], int i2);
uint64_t encode_block(uint64_t jArr[], uint64_t j2);
//byte *encrypt1(byte bArr[], int i2, byte bArr2[], int i3);
//byte *decrypt1(byte bArr[] , int i2, byte bArr2[], int i3);
//byte *encrypt(byte bArr[], byte bArr2[]);
byte *decrypt(byte bArr[], byte bArr2[]);




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

//byte *encrypt1(byte bArr[], int i2, byte bArr2[], int i3) {
//    byte bArr3[] = {0};
//    long j2 = 0;
//    for (int i4 = 0; i4 < 8; i4++) {
//        j2 |= ((long)bArr2[i4]) << (i4 * 8);
//    }
//    int i5 = i2 / 8;
//    long jArr[16] = {0};
//    for (int i6 = 0; i6 < 16; i6++) {
//        jArr[i6] = 0;
//    }
//    long jArr2[] = {0};
//    memcpy(jArr2, 0, i5);
//    for (int i7 = 0; i7 < i5; i7++) {
//        for (int i8 = 0; i8 < 8; i8++) {
//            jArr2[i7] = (((long)bArr[(i7 * 8) + i8]) << (i8 * 8)) | jArr2[i7];
//        }
//    }
//    //long[] jArr3 = new long[((((i5 + 1) * 8) + 1) / 8)];
//    long jArr3[] = { 0 };
//    memcpy(jArr3, 0, ((((i5 + 1) * 8) + 1) / 8));
//    create_subkeys(j2, jArr, 0);
//    for (int i9 = 0; i9 < i5; i9++) {
//        jArr3[i9] = encode_block(jArr, jArr2[i9]);
//    }
//    int i10 = i2 % 8;
//    int i11 = i5 * 8;
//    int i12 = i2 - i11;
//    //byte[] bArr4 = new byte[i12];
//    byte bArr4[] = { 0 };
//    memcpy(bArr4, 0, i12);
//    //System.arraycopy(bArr, i11, bArr4, 0, i12);
//    memcpy(bArr + i11, bArr4, i12);
//    /*for (int i = 0; i < i12; i++) {
//        bArr4[i] = bArr[i11 + i];
//
//    }*/
//    long j3 = 0;
//    for (int i13 = 0; i13 < i10; i13++) {
//        j3 |= ((long)bArr4[i13]) << (i13 * 8);
//    }
//    jArr3[i5] = encode_block(jArr, j3);
//    //bArr3 = new byte[(jArr3.length * 8)];
//    memcpy(bArr3, 0, (sizeof(jArr3)/4)*8);
//    int i14 = 0;
//    int i15 = 0;
//    while (i14 < sizeof(jArr3) / 4) {
//        int i16 = i15;
//        for (int i17 = 0; i17 < 8; i17++) {
//            bArr3[i16] = (byte)((int)(255 & (jArr3[i14] >> (i17 * 8))));
//            i16++;
//        }
//        i14++;
//        i15 = i16;
//    }
//    
//    return bArr3;
//}
//
//byte *decrypt1(byte bArr[] , int i2, byte bArr2[], int i3) {
//    byte bArr3[] = {0};
//    long j2 = 0;
//    for (int i4 = 0; i4 < 8; i4++) {
//        j2 |= ((long)bArr2[i4]) << (i4 * 8);
//    }
//    int i5 = i2 / 8;
//    //long[] jArr = new long[16];
//    long jArr[16] = { 0 };
//    for (int i6 = 0; i6 < 16; i6++) {
//        jArr[i6] = 0;
//    }
//    //long[] jArr2 = new long[i5];
//    long jArr2[] = { 0 };
//    memcpy(jArr2, 0, i5);
//    for (int i7 = 0; i7 < i5; i7++) {
//        for (int i8 = 0; i8 < 8; i8++) {
//            jArr2[i7] = (((long)(bArr[(i7 * 8) + i8] & 255)) << (i8 * 8)) | jArr2[i7];
//        }
//    }
//    //long[] jArr3 = new long[((((i5 + 1) * 8) + 1) / 8)];
//    long jArr3[] = { 0 };
//    memcpy(jArr3, 0, ((((i5 + 1) * 8) + 1) / 8));
//    create_subkeys(j2, jArr, 0);
//    for (int i9 = 0; i9 < i5; i9++) {
//        jArr3[i9] = encode_block(jArr, jArr2[i9]);
//    }
//    int i10 = i2 % 8;
//    int i11 = i5 * 8;
//    int i12 = i2 - i11;
//    //byte[] bArr4 = new byte[i12];
//    byte bArr4[] = { 0 };
//    memcpy(bArr4, 0, i12);
//    //System.arraycopy(bArr, i11, bArr4, 0, i12);
//    memcpy(bArr + i11, bArr4, i12);
//    /*for (int i = 0; i < i12; i++) {
//        bArr4[i] = bArr[i11 + i];
//
//    }*/
//    long j3 = 0;
//    for (int i13 = 0; i13 < i10; i13++) {
//        j3 |= ((long)(bArr4[i13] & 255)) << (i13 * 8);
//    }
//    jArr3[i5] = encode_block(jArr, j3);
//    //bArr3 = new byte[(jArr3.length * 8)];
//    memcpy(bArr3, 0, (sizeof(jArr3) / 4) * 8);
//    int i14 = 0;
//    int i15 = 0;
//    while (i14 < sizeof(jArr3) / 4) {
//        int i16 = i15;
//        for (int i17 = 0; i17 < 8; i17++) {
//            bArr3[i16] = (byte)((int)(255 & (jArr3[i14] >> (i17 * 8))));
//            i16++;
//        }
//        i14++;
//        i15 = i16;
//    }
//    
//    return bArr3;
//}
//
//byte *encrypt(byte bArr[], byte bArr2[]) {
//    long j2;
//    byte bArr3[] = {0};
//    int length = strlen((const char *)bArr);
//    int length2 = strlen((const char*)bArr2);
//    long jArr[16] = {0};
//    int i2 = 0;
//    while (true) {
//        j2 = 0;
//        if (i2 >= 16) {
//            break;
//        }
//        jArr[i2] = 0;
//        i2++;
//    }
//    long j3 = 0;
//    for (int i3 = 0; i3 < 8; i3++) {
//        j3 |= ((long)bArr2[i3]) << (i3 * 8);
//    }
//    create_subkeys(j3, jArr, 0);
//    int i4 = length / 8;
//    //long[] jArr2 = new long[i4];
//    long jArr2[] = { 0 };
//    memcpy(jArr2, 0, i4);
//    for (int i5 = 0; i5 < i4; i5++) {
//        for (int i6 = 0; i6 < 8; i6++) {
//            jArr2[i5] = jArr2[i5] | (((long)(bArr[(i5 * 8) + i6] & 255)) << (i6 * 8));
//        }
//    }
//    //long[] jArr3 = new long[((((i4 + 1) * 8) + 1) / 8)];
//    long jArr3[] = { 0 };
//    memcpy(jArr3, 0, ((((i4 + 1) * 8) + 1) / 8));
//;   for (int i7 = 0; i7 < i4; i7++) {
//        jArr3[i7] = encode_block(jArr, jArr2[i7]);
//    }
//    int i8 = length % 8;
//    int i9 = i4 * 8;
//    int i10 = length - i9;
//    //byte[] bArr4 = new byte[i10];
//    byte bArr4[] = { 0 };
//    memcpy(bArr4, 0, i10);
//    //System.arraycopy(bArr, i9, bArr4, 0, i10);
//    memcpy(bArr+i9, bArr4, i10);
//    for (int i11 = 0; i11 < i8; i11++) {
//        j2 |= ((long)(bArr4[i11] & 255)) << (i11 * 8);
//    }
//    jArr3[i4] = encode_block(jArr, j2);
//    //bArr3 = new byte[(jArr3.length * 8)];
//    memcpy(bArr3, 0, (sizeof(jArr3)/4)*8);
//    int i12 = 0;
//    int i13 = 0;
//    while (i12 < sizeof(jArr3) / 4) {
//        int i14 = i13;
//        for (int i15 = 0; i15 < 8; i15++) {
//            bArr3[i14] = (byte)((int)(255 & (jArr3[i12] >> (i15 * 8))));
//            i14++;
//        }
//        i12++;
//        i13 = i14;
//    }
//    
//    return bArr3;
//}

byte *decrypt(byte bArr[], byte bArr2[]) {
    byte bArr3[280] = {0};

    int length = strlen((const char*)bArr);
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
    uint64_t jArr2[35] = { 0 };
    //memcpy(jArr2, 0, i4);
    for (int i5 = 0; i5 < i4; i5++) {
        for (int i6 = 0; i6 < 8; i6++) {
            jArr2[i5] = jArr2[i5] | (((uint64_t)(bArr[(i5 * 8) + i6] & 255)) << (i6 * 8));
        }
    }
    //long[] jArr3 = new long[i4];
    uint64_t jArr3[35] = { 0 };
    //memcpy(jArr3, 0, i4);
    for (int i7 = 0; i7 < i4; i7++) {
        jArr3[i7] = encode_block(jArr, jArr2[i7]);
    }
    //bArr3 = new byte[(i4 * 8)];
    //memcpy(bArr3, 0, 35*8);
    for (int i8 = 0; i8 < i4; i8++) {
        for (int i9 = 0; i9 < 8; i9++) {
            bArr3[(i8 * 8) + i9] = (byte)((int)(255 & (jArr3[i8] >> (i9 * 8))));
        }
    }
    printf("%s\n", (char*)bArr3);
    return bArr3;
}

int main()
{
    unsigned char encStr[281] = {
        0x86, 0xFA, 0xD6, 0x74, 0xE6, 0xCD, 0xD9, 0xFF, 0x2E, 0xFA, 0xC5, 0x65, 0x26, 0x9D, 0xB5, 0x9E,
        0xDF, 0x50, 0x8D, 0xFC, 0x27, 0x88, 0xCF, 0x17, 0xA7, 0x41, 0x77, 0x5A, 0x36, 0xDB, 0x07, 0xD1,
        0x80, 0xA8, 0xEC, 0x45, 0x51, 0x0F, 0xBC, 0x61, 0xA2, 0x9A, 0x4A, 0x66, 0xDC, 0xDB, 0xA7, 0x17,
        0x54, 0xA6, 0xA3, 0x84, 0x6A, 0xAB, 0xF2, 0x1A, 0xDC, 0x15, 0x6B, 0xD2, 0x7C, 0xFB, 0xB6, 0x9F,
        0x18, 0x8E, 0xAF, 0x86, 0x7F, 0x7D, 0x5D, 0x87, 0xC0, 0xE0, 0xA8, 0xE7, 0x30, 0xF9, 0x95, 0x54,
        0xBF, 0xE7, 0x19, 0x27, 0x0A, 0x64, 0xFF, 0x6C, 0x2C, 0xBC, 0x31, 0x1A, 0x3F, 0x92, 0x49, 0x22,
        0xF6, 0x15, 0x2D, 0x1A, 0x62, 0x0A, 0x24, 0x6A, 0x07, 0x65, 0xBA, 0xE1, 0x08, 0xE6, 0xEE, 0x7B,
        0x95, 0x0E, 0x5B, 0x9D, 0x06, 0x88, 0x6A, 0xC4, 0xD9, 0xEB, 0x9D, 0xA2, 0xE5, 0x38, 0xDD, 0x53,
        0xC5, 0x05, 0x06, 0x3B, 0xC4, 0xDF, 0x25, 0x4A, 0x80, 0x2E, 0xCA, 0x47, 0xBC, 0xB0, 0xFB, 0x11,
        0xD9, 0xEB, 0x9D, 0xA2, 0xE5, 0x38, 0xDD, 0x53, 0x51, 0xD5, 0x37, 0xCB, 0x29, 0xB1, 0x5B, 0x6B,
        0x14, 0x9B, 0x8F, 0x4B, 0xC6, 0xF8, 0xE1, 0x53, 0xF8, 0x86, 0x9F, 0x80, 0xE4, 0x2E, 0xC9, 0xC5,
        0x1F, 0x4E, 0x17, 0x55, 0x2E, 0xED, 0x5E, 0x56, 0xB5, 0xED, 0x77, 0x91, 0xA3, 0x56, 0xD7, 0xE4,
        0xA4, 0xE2, 0x78, 0xA6, 0x49, 0xA3, 0xC1, 0xD8, 0xDA, 0x11, 0x35, 0x2D, 0xE9, 0x26, 0xC9, 0xA0,
        0x3A, 0xF9, 0x70, 0x4A, 0x0F, 0xED, 0x22, 0x28, 0xFD, 0x4A, 0x09, 0xFC, 0x85, 0x46, 0x6B, 0xF2,
        0x7C, 0xEA, 0x5A, 0x49, 0xDE, 0x60, 0x25, 0x74, 0xC9, 0xF9, 0xD9, 0xEF, 0xCD, 0x9F, 0x57, 0x4E,
        0xDA, 0x11, 0x35, 0x2D, 0xE9, 0x26, 0xC9, 0xA0, 0x3A, 0xF9, 0x70, 0x4A, 0x0F, 0xED, 0x22, 0x28,
        0x0D, 0x6B, 0xED, 0xD3, 0xD9, 0x6C, 0x10, 0x9D, 0x21, 0xFC, 0xFC, 0x62, 0x69, 0x94, 0x06, 0x66,
        0x24, 0xEA, 0xB7, 0xCD, 0xBC, 0xA1, 0x7F, 0x31, '\0'
    };


    unsigned char key[9] = {
        0x6B, 0x77, 0x6B, 0x73, 0x26, 0x40, 0x36, 0x39,'\0'    };

    decrypt(encStr, key);
    int a = 20;
    printf("%d",a << 2);




    

    


}

