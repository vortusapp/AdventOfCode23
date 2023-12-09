#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define FPATH "../firstPart/input1.txt"

int isDigit(char input){
    if (    input == '0' ||
            input == '1' ||
            input == '2' ||
            input == '3' ||
            input == '4' ||
            input == '5' ||
            input == '6' ||
            input == '7' ||
            input == '8' ||
            input == '9'
       ) {
        return TRUE;
    }
    return FALSE;
}


int findFirstDigit(char input[]){
    int i;
    for (i=0; i<strlen(input); i++){
        if (isDigit(input[i])){
            return input[i] - '0';
        }
    }
    return 0;
}

int findLastDigit(char input[]){
    int i;
    for (i=strlen(input); i>=0; i--){
        if (isDigit(input[i])){
            return input[i] - '0';
        }
    }
    return 0;
}

int getDigitsFromLine(char input[]){

    return findFirstDigit(input)*10 + findLastDigit(input);
}
int getWordDigit(char *input){
    if (    strlen(input) >= 3 &&
            input[0] == 'o' &&
            input[1] == 'n' &&
            input[2] == 'e'
       ){return 1;}
    if(     strlen(input) >= 3 &&
            input[0] == 't' &&
            input[1] == 'w' &&
            input[2] == 'o'
      ){return 2;}
    if(     strlen(input) >= 5  &&
            input[0] == 't' &&
            input[1] == 'h' &&
            input[2] == 'r' &&
            input[3] == 'e' &&
            input[4] == 'e'
      ){return 3;}
    if(     strlen(input) >= 4 &&
            input[0] == 'f' &&
            input[1] == 'o' &&
            input[2] == 'u' &&
            input[3] == 'r'
      ){return 4;}
    if(     strlen(input) >= 4 &&
            input[0] == 'f' &&
            input[1] == 'i' &&
            input[2] == 'v' &&
            input[3] == 'e'
      ){return 5;}
    if(     strlen(input) >= 3 &&
            input[0] == 's' &&
            input[1] == 'i' &&
            input[2] == 'x'
      ){return 6;}
    if(     strlen(input) >= 5 &&
            input[0] == 's' &&
            input[1] == 'e' &&
            input[2] == 'v' &&
            input[3] == 'e' &&
            input[4] == 'n'
      ){return 7;}
    if(     strlen(input) >= 5 &&
            input[0] == 'e' &&
            input[1] == 'i' &&
            input[2] == 'g' &&
            input[3] == 'h' &&
            input[4] == 't'
      ){return 8;}
    if(     strlen(input) >= 4 &&
            input[0] == 'n' &&
            input[1] == 'i' &&
            input[2] == 'n' &&
            input[3] == 'e'
      ){return  9;}
    return 0;
}


int convertString(char input[]){
    int i;
    int digit;
    int firstSet = 0;
    for (i=0; i<strlen(input); i++){
        int tempDigit;
          if (isDigit(input[i])){
            digit = input[i] - '0';
        } else if ((tempDigit = getWordDigit(&input[i]))){
            digit = tempDigit;
        }
        if (!firstSet && digit){
            firstSet = digit;
            }
    }
    int returnSum = firstSet * 10 + digit;
    return returnSum;
}

int runFile(){
    int sumOfFile = 0;
    FILE *file;
    char line[1024];

    file = fopen(FPATH, "r");
    if(file == NULL){
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file)){
        int lineOutput;
        lineOutput = convertString(line);
        sumOfFile = sumOfFile + lineOutput;
    }
    printf("The file sum is %d \n", sumOfFile);
    fclose(file);
    return EXIT_SUCCESS;
}
