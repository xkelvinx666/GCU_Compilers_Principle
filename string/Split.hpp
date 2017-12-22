//
// Created by xkelvinx666 on 17/12/22.
//
#pragma once
#ifndef PL0_SPLIT_HPP
#define PL0_SPLIT_HPP

#endif //PL0_SPLIT_HPP

#include <vector>
#include <string>
using namespace std;

vector<string> split(string stm, string pattern) {
    size_t startIndex = 0;
    size_t endIndex = 0;
    vector<string>  vec;
    while ((int)(startIndex) <= stm.length() && (int)(startIndex) != -1) {
        endIndex = stm.find_first_of(pattern, startIndex);
        if ((int)(endIndex) <= 0) {
            endIndex = stm.length();
        }
        vec.push_back(stm.substr(startIndex, endIndex - startIndex));
        startIndex = stm.find_first_not_of(pattern, endIndex);
    }
    return vec;
}