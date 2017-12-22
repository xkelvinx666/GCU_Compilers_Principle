#include <fstream>
#include <string>
#include <vector>
#include <fstream>
#include <assert.h>
#include "Operation.hpp"
#include "../string/StrToNumber.h"
#include "../string/Split.hpp"
#include <iostream>

#define GotoTable GotoTableClass *
using namespace std;

class GotoTableClass {
public:
    void readTableFromText(string file) {
        ifstream infile, inLength;
        infile.open(file.data());
        inLength.open(file.data());
        assert(infile.is_open());
        string s;
        int row = 0, col = 0;
        bool isFirstRow = true;
        bool isFirstColumn;
        int rowLen = 0;
        int colLen = 0;
        while (getline(inLength, s)) {
            this->status.push_back(rowLen);
            rowLen++;
        }
        while (getline(infile, s)) {
            isFirstColumn = true;
            vector<string> result = split(s, " ");
            if (result.size() == 0) {
                break;
            }
            OperationList operationList = new vector<Operation>();
            for (col = 0; col < result.size(); col++) {
                if (isFirstRow) {
                    if (isFirstColumn) {
                        isFirstColumn = false;
                        continue;
                    }
                    this->terminators.push_back(result[col]);
                } else if (isFirstColumn) {
                    isFirstColumn = false;
                } else {
                    Operation operation;
                    operation = new OperationClass();
                    if (result[col] != "-1") {
                        operation->setIsOperation(true);
                        operation->setIsGoto(true);
                        string numStr = result[col];
                        operation->setNumber(strToInt(numStr));
                    }
                    operationList->push_back(operation);
                }
            }
            isFirstRow = false;
            this->gotoList.push_back(operationList);
        }
        infile.close();
    }

    void show() {
        auto begin = this->gotoList.begin();
        auto end = this->gotoList.end();
        while (begin != end) {
            for (int j = 0; j < (*begin)->size(); j++) {
                cout << (*(*begin))[j]->getNumber() << " ";
            }
            cout << endl;
            begin++;
        }
    }

private:
    vector<string> terminators;
    vector<int> status;
    vector<OperationList> gotoList;
};