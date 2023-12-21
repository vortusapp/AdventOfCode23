#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXRED 12
#define MAXGREEN 13
#define MAXBLUE 14

int currentGame;
int maxRed = 0, maxGreen = 0, maxBlue = 0;
int powerSum = 0;

int extractColor (char *token){
    int extractedValue = 0;
    char key[100];
    char color[10];
    if(sscanf(token, "%d %s",  &extractedValue, color) == 2) {
        if(strcmp(color, "red") == 0) {
            maxRed = (extractedValue > maxRed) ? extractedValue : maxRed;
            printf("maxRed = %d string is %s \n", maxRed, token);
        } else if(strcmp(color, "blue") == 0) {
            maxBlue = (extractedValue > maxBlue) ? extractedValue : maxBlue;
        } else if(strcmp(color, "green") == 0) {
            maxGreen = (extractedValue > maxGreen) ? extractedValue : maxGreen;
        }
    }
    return extractedValue;
}
int extractGame (char *token){
    int extractedValue = 0;
    char key[100];
    if(strncmp(token, "Game", 4) == 0) {
        if(sscanf(token, "%[^0-9]%d", key, &extractedValue) ==2) {
            printf("Game number %d \n", extractedValue);
            currentGame = extractedValue;
        }
    }
    return extractedValue;
}

int main(int argc, char *argv[])
{
    FILE *filePointer;
    char *filename = "./input.txt";
    char line[1024];
    const char *delimiter = ":;,";
    int invalidGameToken = 0;
    filePointer = fopen(filename, "r");

    if (filePointer == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), filePointer)){
        line[strcspn(line, "\n")] = 0;
        char *token = strtok(line, delimiter);
        while (token != NULL) {
            if(!extractGame(token)){
                if(!extractColor(token)){
                }

            } else {
            }
            token = strtok(NULL, delimiter)  ;
        }
        printf("Time to add \n");
        printf("printSum = %d, maxRed = %d, maxBlue = %d, maxGreen = %d \n", powerSum, maxRed, maxBlue, maxGreen);
        powerSum = powerSum + maxBlue * maxRed * maxGreen;
        maxBlue = 0, maxGreen = 0, maxRed = 0;
    }
printf("The sum of the power of sets is %d \n", powerSum);
    fclose(filePointer);
    return EXIT_SUCCESS;
}
