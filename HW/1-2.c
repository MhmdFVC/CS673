// By Mohamad French for CS 673 Software Engineering at BU MET
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getStringLength(char *input, int maxLength) {
    for (int i = 0; i < maxLength; i++) {
        input[i] = tolower(input[i]); // So capitalization doesn't matter
        if (input[i] == '\0')
            return i-1;
    }
}

int palindromeCheck(char *input, int length) {
    int indexLeft = 0;
    int indexRight = length-1;

    while (indexLeft <= length/2) {
        // Checking for punctuation/spaces and ignoring them
        if (input[indexLeft] == ' ' || input[indexLeft] == '\'' || input[indexLeft] == '\"' || input[indexLeft] == '.' || input[indexLeft] == ',' || input[indexLeft] == ':' || input[indexLeft] == ';' || input[indexLeft] == '!' || input[indexLeft] == '?' || input[indexLeft] == '/') {
            indexLeft++;
            continue;
        }
        if (input[indexRight] == ' ' || input[indexRight] == '\'' || input[indexRight] == '\"' || input[indexRight] == '.' || input[indexRight] == ',' || input[indexRight] == ':' || input[indexRight] == ';' || input[indexRight] == '!' || input[indexRight] == '?' || input[indexRight] == '/') {
            indexRight--;
            continue;
        }

        if (!(input[indexLeft] == input[indexRight]))
            return 0;
        indexLeft++;
        indexRight--;
    } 
}

int main() {
    char *input = malloc(256);
    printf("Enter a string: ");
    fgets(input, 256, stdin);
    if (input[0] == 'q') {
        free(input);
        return 0;
    }

    int length = getStringLength(input, 256);
    //printf("You entered a string of length %d\n", length);

    int isPalindrome = palindromeCheck(input, length);
    printf("The string is");
    if (!isPalindrome)
        printf(" not");
    printf(" a palindrome\n");

    free(input);
    return 0;
}