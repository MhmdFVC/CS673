// By Mohamad French for CS 673 Software Engineering at BU MET
#include <stdio.h>

int table[12][12];
int val = 0;

int print(int num, int eol) { // Print function which makes it easier to print a table
    printf("%d\t", num);
    if (!eol)
        printf("|\t");
    else
        printf("\n");
}

int main() {
    for (int i = 1; i <= 12; i++) { // Main loop
        for (int j = 1; j <= 12; j++) { // Sub-loop which fills out the table and does multiplication
            val = i*j;
            table[i][j] = val;
            table[j][i] = val;
            if (j != 12)
                print(val, 0);
            else
                print(val, 1);
        }
    }
}