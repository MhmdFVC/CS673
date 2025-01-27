// By Mohamad French for CS 673 Software Engineering at BU MET
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *input = malloc(256);
    printf("In one line, enter two strings of equal length using the format [a,b,c], [1,2,3]: ");
    fgets(input, 256, stdin);

    int length, firstListEndIndex=0, secondListStartIndex = 0;

    /////////// Some validation, and getting length and indices of list starts/ends 

    if (input[0] != '[') {
        puts("Your string does not start with a left bracket.");
        free(input);
        return 1;
    }
    
    for (int i = 1; i < 256; i++) {
        if (input[i] == ']' && !firstListEndIndex)
            firstListEndIndex = i;
        else if (input[i] == '[' && !secondListStartIndex)
            secondListStartIndex = i;
        else if (input[i] == '\0') {
            length = i-1;
            break;
        }
    }

    if (input[length-1] != ']') {
        puts("Your string does not end with a right bracket.");
        free(input);
        return 1;
    }

    printf("You entered a string of length %d\n", length);
    printf("First list end index is %d; second list start index is %d\n", firstListEndIndex, secondListStartIndex);
    //////////////////
    char *newString = malloc(length);
    newString[0] = '[';
    int newStringIndex = 1;

    int lengthOfFirstList=0, lengthOfSecondList=0;
    int firstListIndex=1, secondListIndex = secondListStartIndex+1;
    int whichList = 1; // initialize to 1 i.e. second list; this gets reversed on the first run of the loop below, so it starts with the first list

    while (input[secondListIndex] != ']') {
        whichList ^= 1; // Switch between the two lists with each loop

        if (whichList == 0 && input[firstListIndex] != ']') { // i.e. first list
            if (input[firstListIndex] != ',') // Some element has been confirmed
                lengthOfFirstList++;
            while (input[firstListIndex] != ',' && input[firstListIndex] != ']')
                newString[newStringIndex++] = input[firstListIndex++];
            
            newString[newStringIndex++] = ',';
            if (input[firstListIndex] == ']')
                continue;

            firstListIndex++;
        }

        else if (whichList == 1) { // i.e. second list
            if (input[secondListIndex] != ',')
                lengthOfSecondList++;
            while (input[secondListIndex] != ',' && input[secondListIndex] != ']')
                newString[newStringIndex++] = input[secondListIndex++];
            
            if (input[secondListIndex] == ',')
                newString[newStringIndex++] = ',';
            else if (input[secondListIndex] == ']')
                continue;

            secondListIndex++;
        }
    }

    if (secondListStartIndex == 0)
        lengthOfSecondList = 0;

    printf("List 1 length is %d; list 2 length is %d\n", lengthOfFirstList, lengthOfSecondList);
    if (!lengthOfFirstList && !lengthOfSecondList) { // Lists are empty
        puts("Your two lists are empty.");
        free(input);
        free(newString);
        return 1;
    }
    if (lengthOfFirstList != lengthOfSecondList) {
        puts("Your two lists are of different lengths.");
        free(input);
        free(newString);
        return 1;
    }
    //////////////////

    newString[newStringIndex] = ']';
    printf("The new string is: ");
    for (int i = 0; i <= newStringIndex; i++)
        printf("%c", newString[i]);
    puts("");
    
    free(input);
    free(newString);
    return 0;
}