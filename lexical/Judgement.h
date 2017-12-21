#pragma once
#include <string>
using namespace std;

bool isNum(char num) { return (num <= '9' && num >= '0'); }

bool isPoint(char point) { return point == '.'; }

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