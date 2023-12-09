

#include <stdio.h>
#include <assert.h>
#include "./first.c"

void Test_isDigitPassed1_returnsTrue(){
    char input = '1';
    assert(isDigit(input));
}


void Test_isDigitPassedA_returnsFalse(){
    char input = 'a';
    assert(!isDigit(input));
}

void Test_findFirstDigit_returnsDigit(){
    char input[10] = "1abc2";
    assert(findFirstDigit(input) == 1);
}


void Test_findLastDigit_returnsIndex(){
    char input[10] = "1abc2";
    assert(findLastDigit(input) == 2);
}

void Test_getFirstAndLast_makeNumber(){
    char input[10] = "1abc2";
    assert(getDigitsFromLine(input) == 12);
}

int main(int argc, char *argv[])
{
Test_isDigitPassed1_returnsTrue();
Test_isDigitPassedA_returnsFalse();
Test_findFirstDigit_returnsDigit();
Test_findLastDigit_returnsIndex();
Test_getFirstAndLast_makeNumber();
runFile();
}
