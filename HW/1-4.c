// By Mohamad French for CS 673 Software Engineering at BU MET
#include <stdio.h>
#include <stdint.h>

//int toBin()

// I probably need to either just use Python or do some fancy crap to manage massive numbers using arrays of bits. Prob just use python though lol.

int main() {
    // Unsigned 64-bit integers
    uint64_t nPrev = 0;
    uint64_t n = 1;
    uint64_t nNext = 0; // "Temp" variable to manage the handover of values to the "previous n" or nPrev
    printf("Fibonacci number 1: %d\n", n);

    for (int i = 2; i <= 100; i++) {
        nNext = n + nPrev;
        nPrev = n;
        n = nNext;
        printf("Fibonacci number %d: %d\n", i, n);
    }

    return 0;
}