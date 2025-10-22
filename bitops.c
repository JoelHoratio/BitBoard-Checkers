#include "bitboard.h"

unsigned int setBit(unsigned int value, int position) {
    if (position < 0 || position >= 32) return value;
    return value | (1U << position);
}

unsigned int clearBit(unsigned int value, int position) {
    if (position < 0 || position >= 32) return value;
    return value & ~(1U << position);
}

unsigned int toggleBit(unsigned int value, int position) {
    if (position < 0 || position >= 32) return value;
    return value ^ (1U << position);
}

int getBit(unsigned int value, int position) {
    if (position < 0 || position >= 32) return 0;
    return (value >> position) & 1U;
}

int countBits(unsigned int value) {
    int count = 0;
    while (value) {
        count += value & 1U;
        value >>= 1;
    }
    return count;
}

unsigned int shiftLeft(unsigned int value, int positions) {
    return value << positions;
}

unsigned int shiftRight(unsigned int value, int positions) {
    return value >> positions;
}

void printBinary(unsigned int value) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (value >> i) & 1U);
        if (i % 8 == 0) printf(" ");
    }
    printf("\n");
}

void printHex(unsigned int value) {
    printf("0x%X\n", value);
}
