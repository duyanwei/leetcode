/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-03-05
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> data;

        while (n != 1) {
            int m = 0;
            while (n != 0) {
                int res = n % 10;
                m += res * res;
                n /= 10;
            }
            if (data.count(m)) {
                return false;
            }
            data.insert(m);
            n = m;
        }
        return true;
    }
};

/**
 * @brief slow and fast pointer
 *
 * @details similar to the cycled linked list, happy number MUST have a loop!
 *
 */
class Solution2 {
public:
    bool isHappy(int n) {
        std::unordered_set<int> data;
        int slow = n;
        int fast = n;
        do {
            slow = squareDigit(slow);
            fast = squareDigit(fast);
            fast = squareDigit(fast);
        } while (slow != fast);

        return slow == 1;
    }

private:
    int squareDigit(int n) {
        int val = 0;
        while (n != 0) {
            val += (n % 10) * (n % 10);
            n /= 10;
        }
        return val;
    }
};

int main() { return 0; }