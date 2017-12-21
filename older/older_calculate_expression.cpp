#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
typedef struct state *sPointer;
struct state {
    int key;
    string native;
    double value;
    string type;
};

typedef struct queue *qPointer;
struct queue {
    int line;
    string preStr;
    string illegalStr;
    qPointer next;
};
typedef qPointer headQueue;
typedef qPointer tailQueue;

typedef struct stack *stPointer;
struct stack {
    sPointer state;
    stPointer next;
};
typedef stPointer headStack;

headQueue head;
tailQueue tail;

headStack result;

sPointer changeState(char ch) {
    sPointer sp = new state;
    sp->native = ch;
    switch (ch) {
        case '+':
            sp->key = 1;
            break;
        case '-':
            sp->key = 2;
            break;
        case '*':
            sp->key = 3;
            break;
        case '/':
            sp->key = 4;
            break;
        case '(':
            sp->key = 6;
            break;
        case ')':
            sp->key = 7;
            break;
        default:
            sp->key = -1;
            break;
    }
    return sp;
}

void inQueue(qPointer q) {
    tail->next = q;
    q->next = NULL;
    tail = q;
}

void inStack(sPointer sp) {
    stPointer st = new stack;
    st->state = sp;
    st->next = result;
    result = st;
}
sPointer outStack() {
    stPointer st = result;
    result = result->next;
    st->next = NULL;
    return st->state;
}

string charToStr(char ch) {
    char charArr[2];
    charArr[0] = ch;
    charArr[1] = '\0';
    return string(charArr);
}

void addError(string expression, string illegalStr, int count, int index) {
    qPointer q = new queue;
    q->line = count;
    if (index - illegalStr.length() + 1 > 0) {
        q->preStr = charToStr(expression.at(index - illegalStr.length() + 1));
    } else {
        q->preStr = "开头";
    }
    q->illegalStr = illegalStr;
    inQueue(q);
}

void showError() {
    qPointer q;
    int count = 1;
    if (head->next != NULL) {
        head = head->next;
    } else {
        return;
    }
    printf("ERROR:\n");
    while (head != NULL) {
        q = head;
        printf("Error%d:第%d行%s后面存在非法字符“%s”\n", count++, q->line,
               q->preStr.c_str(), q->illegalStr.c_str());
        head = head->next;
    }
}

bool isNum(char num) { return (num <= '9' && num >= '0'); }

bool isPoint(char point) { return point == '.'; }

bool isIllegalInteger(string str) {
    return str.length() >= 2 &&
               str.find_first_of('.') != str.find_last_of('.') ||
           str.at(0) == '.' || str.at(str.length() - 1) == '.';
}

void showState(sPointer sp) {
    switch (sp->key) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
        case 7:
            printf("(%d,%s,NULL,NULL)\n", sp->key, sp->native.c_str());
            break;
        case 5:
            printf("(%d,%s,%d,int)\n", sp->key, sp->native.c_str(),
                   (int)sp->value);
            break;
        case 8:
            printf("(%d,%s,%lf,double)\n", sp->key, sp->native.c_str(),
                   sp->value);
            break;
    }
}

int getData(double *v, string *n, int *i, string expression) {
    //数字的闭包
    double value = *v;
    string native = *n;
    int scale = 1;
    int index = *i;
    while (index + 1 < expression.length() && isNum(expression.at(index + 1))) {
        ++index;
        scale *= 10;
        value = value * 10 + (expression.at(index) - '0');
        native = native + expression.at(index);
    }
    *v = value;
    *n = native;
    *i = index;
    return scale;
}

void appendDemical(int *index, string expression, sPointer *curState) {
    int scale = getData(&((*curState)->value), &((*curState)->native), index,
                        expression);
    (*curState)->key = 8;
    (*curState)->value = (*curState)->value / (double)scale;
}

void appendInteger(int *index, string expression, sPointer *curState) {
    getData(&((*curState)->value), &((*curState)->native), index, expression);
}

sPointer handleHeadPoint(string expression, int *index, int count) {
    sPointer curState = new state;
    //先判断是否为整数
    curState->key = 8;
    curState->value = 0;
    (*index)--;
    while (*index + 1 < expression.length() &&
           expression.at(*index + 1) == '.') {
        //判断0后是否跟.
        (*index)++;
        curState->native = curState->native + '.';
        appendDemical(index, expression, &curState);
    };
    addError(expression, curState->native, count, *index);
}

void handleHeadNumber(char curChar, string expression, int *index, int count) {
    sPointer curState = new state;
    //先判断是否为整数
    curState->key = 5;
    curState->value = curChar - '0';
    curState->native = curChar;
    appendInteger(index, expression, &curState);
    //判断是否为浮点数
    while (*index + 1 < expression.length() &&
           expression.at(*index + 1) == '.') {
        //判断0后是否跟.
        ++(*index);
        curState->native = curState->native + '.';
        appendDemical(index, expression, &curState);
    }
    //非法整数
    if (isIllegalInteger(curState->native)) {
        addError(expression, curState->native, count, *index);
    } else {
        //处理完所有数字输出数字结果
        inStack(curState);
        showState(curState);
    }
}

void getSym(string expression, headQueue head, tailQueue tail, int *count) {
    result = new stack;
    for (int index = 0; index < expression.length(); index++) {
        sPointer curState;
        char curChar = expression.at(index);
        if (isNum(curChar)) {
            handleHeadNumber(curChar, expression, &index, *count);
            //判断是否为.
        } else if (isPoint(curChar)) {
            sPointer curState = handleHeadPoint(expression, &index, *count);
        } else {
            curState = changeState(curChar);
            if (curState->key != -1) {
                inStack(curState);
                showState(curState);
            } else {
                //保存错误到队列中
                addError(expression, charToStr(curChar), *count, index);
            }
        }
    }
    count++;
}

int main(void) {
    string expression;
    head = new queue;
    tail = head;
    int count = 1;
    while (getline(cin, expression) && expression != "$") {
        getSym(expression, head, tail, &count);
    }
    showError();
    return 0;
}