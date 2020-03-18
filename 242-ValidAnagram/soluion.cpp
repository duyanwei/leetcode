/**
 * @file soluion.cpp
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
#include <vector>

using namespace std;

/**
 * @brief hash map
 *
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> base;
        for (size_t i = 0; i < s.length(); i++) {
            if (base.count(s[i])) {
                base[s[i]]++;
            } else {
                base[s[i]] = 0;
            }
        }

        for (size_t i = 0; i < t.length(); i++) {
            if (!base.count(t[i])) {
                return false;
            } else if (base[t[i]] == 0) {
                return false;
            } else {
                base[t[i]]--;
            }
        }
    }
};

/**
 * @brief array of 26 character
 *
 */
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        int base[26];

        for (size_t i = 0; i < 26; i++) {
            base[i] = 0;
        }

        for (size_t i = 0; i < s.length(); i++) {
            base[s[i] - 'a']++;
        }

        for (size_t i = 0; i < t.length(); i++) {
            base[t[i] - 'a']--;
        }

        for (size_t i = 0; i < 26; i++) {
            if (base[i] != 0) {
                return false;
            }
        }

        return true;
    }
};