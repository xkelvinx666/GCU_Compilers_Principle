#include <string>
#include "../error/ErrorList.h"
#include "../string/charToStr.h"
#include "Judgement.h"
#include "LexicalCodeList.h"
using namespace std;

string appendNumberAndPoint(string expression, int *index) {
    //数字闭包用于将数字和.拼接
    string buffer = "";
    while ((*index) < expression.length() &&
           (isNum(expression.at((*index))) || expression.at(*index) == '.')) {
        buffer.append(charToStr(expression.at((*index))));
        ++(*index);
    }
    return buffer;
}

void handleHeadPoint(ErrorList errorList, string expression, int line,
                     int *index) {
    int originalIndex = *index;
    string result = appendNumberAndPoint(expression, index);
    //将所有错误一次全部拼接
    errorList->addError(expression, result, line, originalIndex);
}

void handleHeadNumber(ErrorList errorList, LexicalCodeList lcl,
                      string expression, int line, int *index) {
    int originalIndex = *index;
    int typeCode = 5;
    string result = appendNumberAndPoint(expression, index);
    //如果一串数字中含有两个以上的.报错
    if (result.find_first_of('.') != result.find_last_of('.')) {
        errorList->addError(expression, result, line, originalIndex);
        return;
    } else if (result.find('.') != result.npos) {
        //只有一个.为浮点数
        typeCode = 8;
    }
    lcl->addLexicalCode(result, typeCode);
}