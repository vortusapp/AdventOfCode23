#include <assert.h>
#include "./second.c"

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

void Test_stringHasTwoFirst_returnsDigit(){
    char input[10] = "two1nine";
    assert(getWordDigit(input) == 2);
}

void Test_stringHasOneFirst_returnsDigit(){
    char input[10] = "onetherfd3";
    assert(getWordDigit(input) == 1);
}

void Test_stringHasThreeFirst_returnsDigit(){
    char input[10] = "three234";
    assert(getWordDigit(input) == 3);
}

void Test_stringHasFourFirst_returnsDigit(){
    char input[10] = "four2dss";
    assert(getWordDigit(input) == 4);
}

void Test_stringHasTwoWords_convertString(){
    char input[10] = "fourptwo";
    assert(convertString(input) == 42);
    char input1[10] = "69sixnine";
    assert(convertString(input1) == 69);
    char input2[1024] = "eightseven52five4ninekntfjrdt";
    assert(convertString(input2) == 89);
}
void Test_getWordDigit(){
    assert(getWordDigit("one") == 1);
    assert(getWordDigit("two") == 2);
    assert(getWordDigit("three") == 3);
    assert(getWordDigit("four") == 4);
    assert(getWordDigit("five") == 5);
    assert(getWordDigit("six") == 6);
    assert(getWordDigit("seven") == 7);
    assert(getWordDigit("eight") == 8);
    assert(getWordDigit("nine") == 9);
}


int main(int argc, char *argv[])
{
    Test_isDigitPassed1_returnsTrue();
    Test_isDigitPassedA_returnsFalse();
    Test_findFirstDigit_returnsDigit();
    Test_findLastDigit_returnsIndex();
    Test_getFirstAndLast_makeNumber();
    Test_stringHasTwoFirst_returnsDigit();
    Test_stringHasOneFirst_returnsDigit();
    Test_stringHasThreeFirst_returnsDigit();
    Test_stringHasFourFirst_returnsDigit();
    Test_stringHasTwoWords_convertString();
    Test_getWordDigit();
    runFile();
}
