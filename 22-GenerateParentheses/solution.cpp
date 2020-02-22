/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-02-21
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <string>
#include <vector>

using namespace std;

/**
 * @brief backtracking
 *
 * @TIMECOMPLEXITY
 * @SPACECOMPLEXITY
 *
 */
class Solution {
public:
    vector<string> generateParentheses(int n) {
        vector<string> result;
        std::string str;
        appendParentheses(result, str, 0, 0, n);
        return result;
    }

    void appendParentheses(std::vector<std::string>& result,
                           const std::string& str,
                           const int left,
                           const int right,
                           const int max) {
        if (str.length() == max * 2) {
            result.push_back(str);
        }

        if (left < max) {
            appendParentheses(result, str + "(", left + 1, right, max);
        }
        if (right < left) {
            appendParentheses(result, str + ")", left, right + 1, max);
        }
    }
};