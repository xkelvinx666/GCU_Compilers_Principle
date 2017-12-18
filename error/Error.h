#pragma once
#include <cstdio>
#include <string>
using namespace std;
#define Error ErrorClass*

class ErrorClass {
   public:
    string getPreStr() { return this->preStr; };
    void setPreStr(string preStr) { this->preStr = preStr; };
    string getIllegalStr() { return this->illegalStr; };
    void setIllegalStr(string illegalStr) { this->illegalStr = illegalStr; };
    int getLine() { return this->line; };
    void setLine(int line) { this->line = line; };
    void showError(int count) {
        printf("Error%d:第%d行%s后面存在非法字符“%s”\n", count, this->line,
               this->preStr.c_str(), this->illegalStr.c_str());
    };

   private:
    int line;
    string preStr;
    string illegalStr;
};