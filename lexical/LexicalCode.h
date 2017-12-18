#pragma once
#include <string>
using namespace std;
#define LexicalCode LexicalCodeClass*
class LexicalCodeClass {
   public:
    void setTypeCode(int typeCode) { this->typeCode = typeCode; };
    int getTypeCode() { return this->typeCode; };
    void setOriginal(string original) { this->original = original; };
    string getOriginal() { return this->original; };
    void setOutPut(double output) { this->output = output; };
    double getOutPut() { return this->output; };
    void setType(string type) { this->type = type; };
    string getType() { return this->type; };
    void showLexicalCode() {
        switch (this->typeCode) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 6:
            case 7:
                printf("(%d,%s,NULL,NULL)\n", this->typeCode,
                       this->original.c_str());
                break;
            case 5:
                printf("(%d,%s,%d,int)\n", this->typeCode,
                       this->original.c_str(), (int)this->output);
                break;
            case 8:
                printf("(%d,%s,%lf,double)\n", this->typeCode,
                       this->original.c_str(), this->output);
                break;
        }
    };

   private:
    int typeCode;
    string original;
    double output;
    string type;
};