#include <iostream>
#include "./error/ErrorList.h"
#include "./lexical/Lexical.h"
#include "./syntax/Action.hpp"
#include "./syntax/Goto.hpp"
#include <iostream>
using namespace std;

int main(void) {
    ErrorList errorList = new ErrorListClass();
    string expression;
    Lexical lexical = new LexicalClass();
    ActionTable actionTable = new ActionTableClass();
    actionTable->readTableFromText("../syntax/action.txt");
    GotoTable gotoTable = new GotoTableClass();
    gotoTable->readTableFromText("../syntax/goto.txt");
    gotoTable->show();
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