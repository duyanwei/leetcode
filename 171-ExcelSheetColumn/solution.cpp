/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-03-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (size_t i = 0u; i < s.length(); i++) {
            result += std::pow(26, s.length() - i - 1) * (s.at(i) - 'A' + 1);
        }
        return result;
    }
};