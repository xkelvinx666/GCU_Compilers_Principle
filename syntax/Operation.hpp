#pragma once
#include <vector>
#define Operation OperationClass*
#define OperationList vector<Operation>*

class OperationClass {
   public:
    void setIsOperation(bool isOperation) { this->isOperation = isOperation; }
    void setIsMove(bool isMove) { this->isMove = isMove; }
    void setNumber(int number) { this->number = number; }
    void setIsGoto(bool isGoto) { this->isGoto = isGoto; }
    void setIsACC(bool isACC) {this->isACC = isACC;}
    bool getIsOperation() { return this->isOperation; }
    bool getIsMove() { return this->isMove; }
    int getNumber() { return this->number; }
    int getIsGoto() { return this->isGoto; }
    bool getIsACC() { return this->isACC;}

   private:
    bool isACC = false;
    bool isGoto = false;
    bool isOperation = false;
    bool isMove = false;
    int number = -1;
};