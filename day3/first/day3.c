#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define MAX_ROWS 139
#define MAX_COLS 139
#define TABLE_SIZE 5000
typedef struct {
    int i;
    int j;
} Coordinate;

Coordinate* table[TABLE_SIZE] = {NULL};

unsigned int hashCoordinate(Coordinate coord) {
    return (coord.i * 61 + coord.j ) % TABLE_SIZE;
}

int isChecked(int i, int j){
    Coordinate coord = {i, j};
    unsigned int hash = hashCoordinate(coord);
    return table[hash] != NULL;
}

void checkNumber(int i, int j){
    Coordinate coord = {i, j};
    unsigned int hash = hashCoordinate(coord);
    if (table[hash] == NULL) {
        table[hash] = malloc(sizeof(Coordinate));
        *table[hash] = coord;
    }
}

char matrix[MAX_ROWS][MAX_COLS] ;
int partNumberSum = 0;

int isSymbol(char ch){
    return (
            (ch >= 33   && ch <= 45) ||
            (ch == 47) ||
            (ch >= 58   && ch <= 64) ||
            (ch >= 91   && ch <= 96) ||
            (ch >= 123  && ch <= 126)
            );
}


int isNumber(char ch){
    return (ch >= '0' && ch <= '9');
}

void getWholeNumber(int i, int j){
    if(isChecked(i, j)){
        return;
    }
    int number = 0;
    while(j >= 0 && isNumber(matrix[i][j])){
        j--;
    }
    j++;
    while(j <= MAX_COLS && isNumber(matrix[i][j])){
        checkNumber(i, j);
        number = number * 10 + matrix[i][j] - '0';
        j++;
    }
    printf("The number is %d, the running total is %d\n",
            number, partNumberSum);
    partNumberSum = partNumberSum + number;
}
void findSurroundingNumbers (int i, int j){
    int k, l;
    for (k=(i-1); k<=(i+1); k++){
        if(k<0 || k>MAX_ROWS ){
            break;
        }
        for (l=(j-1); l<=(j+1); l++){
            if ( l<0 || l>MAX_COLS){
                break;
            }
            if (isNumber(matrix[k][l])){
                getWholeNumber(k,l);
            }
        }
    }
}



void traverseMatrix(){
    for (int i = 0; i < MAX_ROWS; i++){
        for(int j = 0; j < MAX_COLS; j++){
            if(isSymbol(matrix[i][j])){
                findSurroundingNumbers(i,j);
            }
        }
    }
}

void loadFile(){

    FILE *filePointer;

    filePointer = fopen("./input.txt", "r");
    if(filePointer == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    } else {
    }

    for (int i = 0; i < MAX_ROWS; i++){
        if(fgets(matrix[i], MAX_COLS, filePointer) == NULL){
            break;
        }
        int c;
        while((c = fgetc(filePointer)) != '\n' && c!=EOF);
    }

    fclose(filePointer);
}

int start(){
    loadFile();
    traverseMatrix();
printf("Total codes is %d\n", partNumberSum);
    return EXIT_SUCCESS;
}
