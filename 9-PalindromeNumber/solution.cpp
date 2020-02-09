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
#include <vector>

using namespace std;

/**
 * @brief brute-force
 *
 * @TimeComplexity log(x)
 * @SpaceComplexity log(x)
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        vector<int> values;
        while (x) {
            values.push_back(x % 10);
            x /= 10;
        }

        const size_t size = values.size();
        const size_t half_size = values.size() / 2;

        for (size_t i = 0, j = size - i - 1; i < half_size; i++, j--) {
            if (values.at(i) != values.at(j)) {
                return false;
            }
        }
        return true;
    }
};

/**
 * @brief reverse half of the value
 *
 * @details Q: how to judge if we already reversed half of the value?
 *          A: compare the value after each digit reverse
 *
 * @TimeComplexity log(x) / 2
 * @SpaceComplexity O(1) constant
 *
 */
class Solution2 {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x % 10 == 0 && x != 0) {
            return false;
        }

        int result = 0;
        while (true) {  // be sure the loop could end properly (avoid dead loop
                        // )!!!
            result = result * 10 + x % 10;

            if (result == x || result == x / 10) {  // palindrome
                return true;
            }

            x /= 10;

            if (x < result) {
                return false;
            }
        }
    }
};

/**
 * @details summary
 * if uses a string or vector to store the reverse digit of the value,
 * everything should be fine; however if uses another integer to store the
 * reverse of the value, be careful with value that ends with '0', e.g. 10, 100,
 * 1000, as its reverse '01' or '001' is not a valid value neither it satisfies
 * the requirement, while it could mess your algorithm
 */

int main() {
    Solution2 s;
    std::cout << s.isPalindrome(121) << std::endl;
    return 0;
}