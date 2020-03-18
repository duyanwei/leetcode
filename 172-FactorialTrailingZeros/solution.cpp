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

#include <iostream>

/**
 * @brief solution
 *
 * @ref https://www.cnblogs.com/grandyang/p/4219878.html
 *
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        while (n > 0) {
            result += n / 5;
            n /= 5;
        }

        return result;
    }
};

/**
 * @brief
 *
 */
class Solution2 {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};

int main() {
    Solution2 s;
    std::cout << s.trailingZeroes(19) << std::endl;
    return 0;
}