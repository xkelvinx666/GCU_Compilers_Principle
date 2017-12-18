#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
typedef struct node *pointer;
struct node {
    int key;
    string value;
    double dbValue;
    string type;
    int intValue;
};
// typedef struct node *pointer;
// struct node {
//     char ch;
//     pointer next;
// };

// void getIn(char ch, pointer *tail) {
//     pointer p = new node;
//     p->ch = ch;
//     (*tail)->next = p;
//     (*tail) = p;
// }

// char getOut(pointer header) {
//     char ch = header->ch;
//     pointer p = header;
//     header = header->next;
//     delete p;
//     return ch;
// }

// int size(pointer header, pointer tail) {
//     int count = 0;
//     while (header != tail) {
//         count++;
//         header = header->next;
//     }
//     return count;
// }

int judgeCharEnd(char ch) {
    int result = 0;
    switch (ch) {
    case '+':
        result = 1;
        break;
    case '-':
        result = 2;
        break;
    case '*':
        result = 3;
        break;
    case '/':
        result = 4;
        break;
    case '(':
        result = 6;
        break;
    case ')':
        result = 7;
        break;
    default:
        result = -1;
        break;
    }
    return result;
}
bool isNum(char num) { return (num <= '9' && num >= '0'); }
int getSym() {
    string expression;
    while (cin >> expression) {
        // pointer numHeader = new node;
        // pointer numTail = numHeader;
        for (int index = 0; index < expression.length(); index++) {
            char ch = expression.at(index);
            if (ch != '\n' && ch != '\r') {
                int testChar = judgeCharEnd(ch);
                if (testChar != -1) {
                    printf("(%d,%c,NULL,NULL)", testChar, ch);
                }
                if (isNum(ch)) {
                    if (ch == '0') {
                        if (index + 1 < expression.length() &&
                            expression.at(index + 1) == '.') {
                            //判断0后是否跟.
                            ++index;
                            double total = 0;
                            pointer p = new node;
                            p->intValue = 1;
                            p->dbValue = 0;
                            p->value = "0.";
                            while (index + 1 < expression.length() &&
                                   isNum(expression.at(index + 1))) {
                                ++index;
                                p->intValue *= 10;
                                p->dbValue = p->dbValue * 10 +
                                             (expression.at(index) - '0');
                                p->value = p->value + expression.at(index);
                            }
                            if (p->intValue == 1) {
                                printf("error");
                            } else {
                                total = p->dbValue / p->intValue;
                                p->dbValue = total;
                                printf("(%d,%s,%.1lf,double)", 8,
                                       p->value.c_str(), p->dbValue);
                            }
                        } else {
                            //整数0输出
                            printf("(%d,%c,%d,int)", 5, ch, ch - '0');
                        }
                    } else {
                        double total = ch - '0';
                        while (index + 1 < expression.length() &&
                               isNum(expression.at(index + 1))) {
                            total =
                                total * 10 + (expression.at(index + 1) - '0');
                            ++index;
                        }
                        // getIn(ch, &numTail);
                    }
                } else {
                    printf("error");
                }
            }
        }
    }
}
int main(void) {
    getSym();
    return 0;
}