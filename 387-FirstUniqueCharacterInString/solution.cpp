/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-03-18
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <string>
#include <unordered_map>

using namespace std;

/**
 * @brief solution
 *
 * @TIMECOMPLEXITY O(n)
 * @SPACECOMPLEXITY O(n)
 *
 */
class Solution {
public:
    int firstUniqChar(string s) {
        std::unordered_map<char, int> base;
        for (size_t i = 0u; i < s.length(); i++) {
            if (base.count(s[i])) {
                base[s[i]]++;
            } else {
                base[s[i]] = 1;
            }
        }

        // index can be quried from second loop
        for (size_t i = 0u; i < s.length(); i++) {
            if (base[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};