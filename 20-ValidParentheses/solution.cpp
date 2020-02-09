/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-02-02
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> buffer;
        for (size_t i = 0; i < s.length(); i++) {
            const char c = s[i];
            if (c == '(' || c == '{' || c == '[') {
                buffer.push(c);
            } else {
                if (buffer.empty()) {
                    return false;
                } else {
                    const char b = buffer.top();
                    if ((c == ')' && b == '(') || (c == ']' && b == '[') ||
                        (c == '}' && b == '{')) {
                        buffer.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        return buffer.empty();  // be careful with the last judgement, a valid
                                // string should result an empty stack
    }
};

int main() {
    const string s("[][]{}()");
    Solution so;
    std::cout << so.isValid(s) << std::endl;
    return 0;
}