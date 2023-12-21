#include "./day3.c"
#include <assert.h>

void test_PassSymbol_isSymbolReturnsFalse(){
    assert(isSymbol('%'));
}

void test_PassNumber_isSymbolReturnsTrue(){
    assert(!isSymbol('1'));
}

void test_PassPeriod_isSymbolReturnTrue(){
    assert(!isSymbol('.'));
}

void mockMatrix(){
   char data[10][10] = {
        {'4', '6', '7', '.', '.', '.', '1', '1', '4', '.'},
        {'.', '.', '.', '*', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '3', '5', '.', '.', '6', '3', '3', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '#', '.', '.'},
        {'6', '1', '7', '*', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '+', '.', '5', '8', '.'},
        {'.', '.', '5', '9', '2', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '7', '5', '5', '.'},
        {'.', '.', '.', '$', '.', '*', '.', '.', '.', '.'},
        {'.', '6', '6', '4', '.', '5', '9', '8', '.', '.'}
    };
     for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = data[i][j];
        }
    }
traverseMatrix();
printf("Total codes is %d\n", partNumberSum);

}

void printMatrix(){
    for(int i = 0; i < MAX_ROWS; i++){
        for (int j = 0; j < MAX_COLS; j++){
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
test_PassSymbol_isSymbolReturnsFalse();
test_PassNumber_isSymbolReturnsTrue();
test_PassPeriod_isSymbolReturnTrue();
//start();
//mockMatrix();
loadFile();
printMatrix();
    return EXIT_SUCCESS;
}
