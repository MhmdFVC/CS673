// By Mohamad French for CS 673 Software Engineering at BU MET
#include <stdio.h>

int main() {
    int year = 0;
    printf("Enter a year to check if it is a leap year: ");
    scanf("%d", &year);

    if (!(year%4 == 0) || (year%100 == 0 && !(year%400 == 0))) {
        printf("%d is not a leap year.\n", year);
        return 0;
    }

    printf("%d is a leap year.\n", year);
}