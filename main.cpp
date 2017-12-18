#include <iostream>
#include <string>
#include "./error/ErrorList.h"
#include "./lexical/Lexical.h"
#include "./lexical/LexicalCodeList.h"
using namespace std;

int main(void) {
    ErrorList errorList = new ErrorListClass();
    string expression;
    Lexical lexical = new LexicalClass();
    int line = 0;
    while (getline(cin, expression) && expression != "$") {
        ++line;
        LexicalCodeList lexicalCodeList = new LexicalCodeListClass();
        lexical->analysis(errorList, lexicalCodeList, expression, line);
        lexicalCodeList->show();
    }
    errorList->showError();
    return 0;
}