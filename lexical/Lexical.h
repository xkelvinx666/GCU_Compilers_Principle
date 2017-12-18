#include <string>
#include "Judgement.h"
#include "LexicalCodeList.h"
#include "LexicalDFA.h"
#include "TypeCode.h"
#define Lexical LexicalClass*
using namespace std;

class LexicalClass {
   public:
    bool analysis(ErrorList errorList, LexicalCodeList lexicalCodeList,
                  string expression, int line) {
        for (int index = 0; index < expression.length(); index++) {
            char currentChar = expression.at(index);
            if (isNum(currentChar)) {  //判断是否为数字
                handleHeadNumber(errorList, lexicalCodeList, expression, line,
                                 &index);
            } else if (isPoint(currentChar)) {  //判断是否为.
                handleHeadPoint(errorList, expression, line, &index);
            } else if (isSymbol(currentChar)) {  //判断是否为符号
                lexicalCodeList->addLexicalCode(
                    charToStr(expression.at(index)),
                    getTypeCode(expression.at(index)));
            } else {  //非法字符，报错
                errorList->addError(expression, charToStr(currentChar), line,
                                    index);
            }
        }
    }
    bool getResult(){

    };

   private:
};