#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXRED 12
#define MAXGREEN 13
#define MAXBLUE 14

int currentGame;
int successfulGameSum = 0;

int extractColor (char *token){
    int extractedValue = 0;
    char key[100];
    char color[10];
    if(sscanf(token, "%d %s",  &extractedValue, color) == 2) {
        if(strcmp(color, "red") == 0) {
            if(MAXRED < extractedValue){
                printf("Game %d invalid\n", currentGame);
                return 0;
            }
        } else if(strcmp(color, "blue") == 0) {
            if(MAXBLUE < extractedValue){
                printf("Game %d invalid\n", currentGame);
                return 0;
            }
        } else if(strcmp(color, "green") == 0) {
            if(MAXGREEN < extractedValue){
                printf("Game %d invalid\n", currentGame);
                return 0;
            }
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
                   goto nextIteration;
                }
            }
            token = strtok(NULL, delimiter)  ;
        }
        successfulGameSum = successfulGameSum + currentGame;
nextIteration: ;
    }
printf("The sum of invalid game numbers is %d \n", successfulGameSum);
    fclose(filePointer);
    return EXIT_SUCCESS;
}
