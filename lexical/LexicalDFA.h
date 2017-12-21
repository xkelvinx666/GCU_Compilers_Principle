#include <iostream>
#include <string>
#include "../error/ErrorList.h"
#include "../string/charToStr.h"
#include "Judgement.h"
#include "LexicalCodeList.h"
using namespace std;

void closureNumber(string expression, int *index, string *buffer) {
    //闭包所有数字
    while ((*index) < expression.length() && isNum(expression.at((*index)))) {
        buffer->append(charToStr(expression.at((*index))));
        ++(*index);
    }
    --(*index);
}

void closureExceptSymbol(string expression, int *index, string *buffer) {
    //闭包将所有非法字符合并
    while ((*index) < expression.length() &&
           !isSymbol(expression.at((*index)))) {
        buffer->append(charToStr(expression.at((*index))));
        ++(*index);
    }
    --(*index);
}

void handleHeadIllegal(ErrorList errorList, string expression, int line,
                       int *index) {
    int originalIndex = *index;
    //跳过打头点的判断
    string result = "";
    //闭包所有错误串
    closureExceptSymbol(expression, index, &result);
    errorList->addError(expression, result, line, originalIndex);
}

void handleHeadNumber(ErrorList errorList, LexicalCodeList lcl,
                      string expression, int line, int *index) {
    int originalIndex = *index;
    int typeCode = 5;
    string result = "";
    closureNumber(expression, index, &result);
    //符合整数情况
    if (*index == expression.length() || isSymbol(expression.at(*index + 1))) {
        typeCode = 5;
    }
    //如果还有后跟符号
    if (*index + 1 < expression.length()) {
        //如果下一个符号是.可能符合浮点数情况
        if (expression.at(*index + 1) == '.') {
            //已判断.直接处理
            result.append(".");
            //下标前进两格以跳到第一个小数
            (*index)++;
            (*index)++;
            closureNumber(expression, index, &result);
            typeCode = 8;
        }
        //如果下一个符号不是运算符则此串均无效
        if (*index + 1 < expression.length() &&
            !isSymbol(expression.at(*index + 1))) {
            cout << "test3" << endl;
            closureExceptSymbol(expression, index, &result);
            typeCode = -1;
        }
    }
    if (typeCode != -1) {
        lcl->addLexicalCode(result, typeCode);
    } else {
        errorList->addError(expression, result, line, originalIndex);
    }
}