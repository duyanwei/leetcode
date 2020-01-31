/**
 * @brief
 *
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        const size_t len = s.length();
        for (size_t i = 0; i < len; i++) {
            for (size_t j = i + 1; j <= len; j++) {
                const string substr = s.substr(i, j - i);
                const int valid_len = validString(substr);
                result = result < valid_len ? valid_len : result;
            }
        }
        return result;
    }

private:
    int validString(const string& s) const {
        int result = 0;
        unordered_set<char> data;
        for (size_t i = 0; i < s.length(); i++) {
            if (data.count(s.at(i))) {
                break;
            }
            data.emplace(s.at(i));
            result++;
        }
        return result;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        unordered_map<char, size_t> data;
        const size_t len = s.length();
        for (size_t i = 0, j = 0; i < len; i++) {
            if (data.count(s.at(i))) {
                const size_t cur_len = data.at(s.at(i));
                j = j < cur_len ? cur_len : j;
            }
            data[s.at(i)] = i + 1;
            result = result < i - j + 1 ? i - j + 1 : result;
        }
        return result;
    }
};

int main() {
    const std::string str(
        "udsgtcazkdgyijogsuvspkqrfrmgyauufocatczdhidpttxlntgdfwwnnktnmqhrejtxmu"
        "cveflxzkjmdrr");
    Solution s;
    std::cout << s.lengthOfLongestSubstring(str) << std::endl;
    return 0;
}