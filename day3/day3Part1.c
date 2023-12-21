#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 140



void scanAround(int i, int j);
void getFullNumber(int i, int j);
int hasNumberAlreadyBeenFound(int numberHash);
int hashNumber(int i, int j);


char input[MAXLINE][MAXLINE + 1];
int completedNumbers[10240];
int completedNumbersIndex = 0;
int sumOfNumbers = 0;

int main(void){
    FILE *fp;
    char line[MAXLINE];
    int lineNumber = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL){
        exit(EXIT_FAILURE);
    }
    while (fgets(input[lineNumber], MAXLINE + 2, fp) != NULL){
        lineNumber++;
    }

    for (int i =0; i < MAXLINE; i++){
        for (int j = 0; j < MAXLINE; j++){
            if (ispunct(input[i][j]) && input[i][j] != '.'){
                printf("PUNCTUATION FOUND AT %d,%d\n" , i, j);
                scanAround(i, j);
            }
        }
    }


    fclose(fp);

    printf("\n \n \n SUM OF NUMBERS: %d\n", sumOfNumbers);

    return EXIT_SUCCESS;
}

void scanAround(int i, int j){
    for (int k = i - 1; k <= i + 1; k++){
        for (int l = j - 1; l <= j + 1; l++){
            if (k >= 0 && k < MAXLINE && l >= 0 && l < MAXLINE){
                if (isdigit(input[k][l])){
                    printf("FOUND A DIGIT AT %d,%d\n", k, l);
                    getFullNumber(k, l);
                }
            }

        }
    }
}

void getFullNumber(int i, int j){
    int number = 0;
    while (isdigit(input[i][j])){
        j--;
    }
    j++;
    while (isdigit(input[i][j])){
        number = number * 10 + (input[i][j] - '0');
        j++;
    }
    if (hasNumberAlreadyBeenFound(hashNumber(i, j))){
        printf("NUMBER ALREADY FOUND: %d\n", number);
    } else {
        completedNumbers[completedNumbersIndex] = hashNumber(i, j);
        completedNumbersIndex++;
        printf("NUMBER FOUND: %d\n", number);
        sumOfNumbers += number;
    }
}


int hasNumberAlreadyBeenFound(int numberHash){
    for (int i = 0; i < completedNumbersIndex; i++){
        if (completedNumbers[i] == numberHash){
            return 1;
        }
    }
    return 0;
}

int hashNumber(int i, int j){
    return i*193 + j;
}

