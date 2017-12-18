#pragma once
#include <vector>
#include "../string/charToStr.h"
#include "Error.h"
#define ErrorList ErrorListClass*
using namespace std;

class ErrorListClass {
   public:
    bool add(Error e) { this->vec.push_back(e); }
    bool addError(string expression, string illegalStr, int line, int index) {
        Error e = new ErrorClass();
        if (index == 0) {
            e->setPreStr("开头");
        } else {
            e->setPreStr(
                charToStr(expression.at(index - illegalStr.length() + 1)));
        }
        e->setLine(line);
        e->setIllegalStr(illegalStr);
        this->add(e);
    }
    bool showError() {
        int index = 0;
        vector<Error>::iterator begin = this->vec.begin();
        vector<Error>::iterator end = this->vec.end();
        while (begin != end) {
            index++;
            (*begin)->showError(index);
            begin++;
        }
    }

   private:
    vector<Error> vec;
};