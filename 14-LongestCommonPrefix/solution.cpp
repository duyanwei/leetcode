/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-02-01
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief verticla scanning
 *
 * @details first loop over first string, second loop other strings in the same
 * position
 *
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return string();
        }

        for (size_t i = 0; i < strs.at(0).length(); i++) {
            const char c = strs.at(0).at(i);
            for (size_t j = 1; j < strs.size(); j++) {
                if (i == strs.at(j).length() || c != strs.at(j).at(i)) {
                    return strs.at(0).substr(0, i);
                }
            }
        }
        return strs.at(0);
    }
};