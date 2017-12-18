#pragma once
#include <iostream>
#include <string>
using namespace std;
int strToInt(string original) {
    int value = 0;
    for (int index = 0, length = original.length(); index < length; index++) {
        if (original.at(index) == '.') {
            continue;
        }
        value = value * 10 + (original.at(index) - '0');
    }
    return value;
}

double strToDouble(string original) {
    double total = (double)strToInt(original);
    int intLength = 0;
    while (intLength < original.length()) {
        if (original.at(intLength) == '.') {
            break;
        }
        intLength++;
    }
    int smallScale = original.length() - (intLength + 1);
    while (smallScale-- > 0) {
        total /= 10.0;
    }
    return total;
}