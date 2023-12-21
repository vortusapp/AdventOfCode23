#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 140



int scanAround(int i, int j);
int getFullNumber(int i, int j, int usedNumbers[], int numberOfNumbers);
int hashNumber(int i, int j);
int isNumberUsed (int i, int j, int usedNumbers[], int completedNumbersIndex);

char input[MAXLINE][MAXLINE + 1];
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
            if (input[i][j] == '*'){
                int gearRatio = scanAround(i, j);
                printf("GEAR RATIO IS %d \n",gearRatio);
                sumOfNumbers += gearRatio;
            }
        }
    }


    fclose(fp);

    printf(" \n \n \n SUM OF NUMBERS IS %d\n", sumOfNumbers);
    return EXIT_SUCCESS;
}

int scanAround(int i, int j){
    int usedNumbers[12];
    int  storedNumbers[12];
    int  numberOfNumbers = 0;
    for (int k = i - 1; k <= i + 1; k++){
        for (int l = j - 1; l <= j + 1; l++){

            if (k >= 0 && k < MAXLINE && l >= 0 && l < MAXLINE){
                if (isdigit(input[k][l])){
                    printf("FOUND A DIGIT AT %d,%d\n", k, l);
                    int fullNumber = getFullNumber(k, l, usedNumbers, numberOfNumbers);
                    if (fullNumber != 0){
                        printf("FULL NUMBER IS %d\n", fullNumber);
                        storedNumbers[numberOfNumbers] = fullNumber;
                        numberOfNumbers++;
                    }
                }
            }

        }
    }
    if (numberOfNumbers > 2){
                printf("TOO MANY NUMBERS FOUND\n");
                return 0;
            }
    if (numberOfNumbers == 2){
        printf("TWO NUMBERS FOUND\n");
        return storedNumbers[0] * storedNumbers[1];
    }
        printf("NOT ENOUGH NUMBERS FOUND\n");
        return 0;

}

int isNumberUsed (int i, int j, int usedNumbers[], int completedNumbersIndex){
    int number = hashNumber(i, j);
    for (int k = 0; k < completedNumbersIndex; k++){
        if (usedNumbers[k] == number){
            return 1;
        }
    }
    return 0;
}
int getFullNumber(int i, int j, int usedNumbers[], int numberOfNumbers){
    int number = 0;
    while (isdigit(input[i][j])){
        j--;
    }
    j++;
    if (isNumberUsed(i, j, usedNumbers, numberOfNumbers)){
        return 0;
    }

    usedNumbers[numberOfNumbers] = hashNumber(i, j);
    while (isdigit(input[i][j])){
        number = number * 10 + (input[i][j] - '0');
        j++;
    }

    return number;
}

int hashNumber(int i, int j){
    return i*193 + j;
}

