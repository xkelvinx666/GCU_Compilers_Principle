#include <string>
#include "Judgement.h"
#include "LexicalCodeList.h"
#include "LexicalDFA.h"
#include "TypeCode.h"
#define Lexical LexicalClass*
using namespace std;

class LexicalClass {
   public:
    void analysis(ErrorList errorList, LexicalCodeList lexicalCodeList,
                  string expression, int line) {
        for (int index = 0; index < expression.length(); index++) {
            char currentChar = expression.at(index);
            if (isNum(currentChar)) {  //判断是否为数字
                handleHeadNumber(errorList, lexicalCodeList, expression, line,
                                 &index);
            } else if (isSymbol(currentChar)) {  //判断是否为符号
                lexicalCodeList->addLexicalCode(
                    charToStr(expression.at(index)),
                    getTypeCode(expression.at(index)));
            } else {  //非法字符，闭包处理，报错非法字符，报错
                handleHeadIllegal(errorList, expression, line, &index);
            }
        }
    }
};