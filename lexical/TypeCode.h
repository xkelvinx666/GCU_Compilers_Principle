#pragma once
#include <string>
#include "../string/StrToNumber.h"
using namespace std;

int getTypeCode(char ch) {
    int code = -1;
    switch (ch) {
        case '+':
            code = 1;
            break;
        case '-':
            code = 2;
            break;
        case '*':
            code = 3;
            break;
        case '/':
            code = 4;
            break;
        case '(':
            code = 6;
            break;
        case ')':
            code = 7;
            break;
        default:
            code = -1;
            break;
    }
    return code;
}

string getTypeByTypeCode(int typeCode) {
    switch (typeCode) {
        case 5:
            return "int";
        case 8:
            return "double";
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
        case 7:
        default:
            return "NULL";
    }
}

double getValue(string original, int typeCode) {
    switch (typeCode) {
        case 5:
            return strToInt(original);
        case 8:
            return strToDouble(original);
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
        case 7:
        default:
            return 0;
    }
}