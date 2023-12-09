#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define FPATH "./input1.txt"

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
        sumOfFile = sumOfFile + getDigitsFromLine(line);
    }
    printf("%d", sumOfFile);
    fclose(file);
    return EXIT_SUCCESS;
}
