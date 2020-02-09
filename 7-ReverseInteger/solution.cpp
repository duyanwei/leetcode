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

#include <climits>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * @brief
 *
 * SPACE complexity: O(log(x))
 *
 */
class Solution {
public:
    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;
        x *= sign;  // if x = -128, it can fail
        stack<int> s;
        while (x > 0) {  // x is already pivoted with sign, it's ok to judge it
            s.push(x % 10);
            x = x / 10;
        }

        while ((!s.empty()) && (s.top() == 0)) {
            s.pop();
        }

        int result = 0;
        int value = 1;
        while (!s.empty()) {
            result += s.top() * value;
            value *= 10;
            s.pop();
        }

        return result * sign;
    }
};

class Solution2 {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {  // be careful, x can be negative

            int temp = result * 10 + x % 10;  // causes overflow
            if (temp / 10 != result) {
                return 0;
            }
            result = temp;
            x = x / 10;
        }
        return result;
    }
};

/**
 * @brief
 *
 * Integer.MAX_VALUE = 2147483647 (pop = 7)
 * Integer.MIN_VALUE = -2147483648 (pop = -8)
 *
 * Time Complexity: O(log(x)). There are roughly log_{10}(x) digits in xx.
 * Space Complexity: O(1).
 */
class Solution3 {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int pop = x % 10;
            x = x / 10;
            if (result > INT_MAX / 10 || result == INT_MAX / 10 && pop > 7) {
                return 0;
            }
            if (result < INT_MIN / 10 || result == INT_MIN / 10 && pop < -8) {
                return 0;
            }
            result = result * 10 + pop;
        }
        return result;
    }
};

int main() {
    Solution2 s;
    std::cout << s.reverse(-987) << std::endl;
    std::cout << long(1 << 31) << std::endl;
    return 0;
}