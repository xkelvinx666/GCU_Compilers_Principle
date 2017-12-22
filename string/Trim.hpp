//
// Created by xkelvinx666 on 17/12/22.
//

#include <cstring>
#include <string>

#ifndef PL0_TRIM_HPP
#define PL0_TRIM_HPP

#endif //PL0_TRIM_HPP

using namespace std;

string trim(string stm) {
    size_t start = stm.find_first_not_of(' ');
    size_t end = stm.find_last_not_of(' ');
    return stm.substr(start, end - start + 1);
}