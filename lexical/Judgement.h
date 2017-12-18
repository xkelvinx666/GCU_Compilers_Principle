#pragma once
#include <string>
using namespace std;

bool isNum(char num) { return (num <= '9' && num >= '0'); }

bool isPoint(char point) { return point == '.'; }

bool isIllegalInteger(string str) {
    return str.length() >= 2 &&
               str.find_first_of('.') != str.find_last_of('.') ||
           str.at(0) == '.' || str.at(str.length() - 1) == '.';
}

bool isSymbol(char symbol) {
    bool isSymbol = false;
    switch (symbol) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
            isSymbol = true;
            break;
        default:
            isSymbol = false;
            break;
    }
    return isSymbol;
}