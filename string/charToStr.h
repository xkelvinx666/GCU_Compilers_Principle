#pragma once
#include <string>
using namespace std;

string charToStr(char ch) {
    char charArr[2];
    charArr[0] = ch;
    charArr[1] = '\0';
    return string(charArr);
}