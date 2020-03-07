/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-03-01
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief
 *
 * @details failure case: "0P", as 'P' - '0' = 32 ('a' - 'A' = 32)
 *          use std::tolower convert upper case to lower before checking
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            while (left < s.length() && !isLetter(s.at(left))) {
                left++;
            }

            while (right >= 0 && !isLetter(s.at(right))) {
                right--;
            }

            if (left > right) {
                break;
            }

            if (tolower(s.at(left)) != tolower(s.at(right))) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

private:
    bool isLetter(const char c) const {
        return (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A') ||
               (c <= '9' && c >= '0');
    }
};

int main() {
    Solution ss;
    string s("0P");
    std::cout << ss.isPalindrome(s) << std::endl;
    return 0;
}