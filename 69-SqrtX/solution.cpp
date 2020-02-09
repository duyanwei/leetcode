/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-02-03
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }

        const int half = x / 2;
        for (int i = half; i >= 0; i--) {
            if (i * i <= x) {  // overflow
                return i;
            }
        }
        return 0;
    }
};

class Solution1 {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }

        const int half = x / 2;
        for (int i = half; i >= 0; i--) {
            if (i <= x / i) {  // no overflow, but slow (O(log(N)))
                return i;
            }
        }
        return 0;
    }
};

class Solution2 {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }

        int left = 1;  // dichotomy (cannot be zero)
        int right = x / 2;
        while (left <= right) {
            const int mid = (left + (right - left) / 2);
            if (mid == x / mid) {
                return mid;
            } else if (mid > x / mid) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
};

class Solution3 {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }

        return 0;
        // @todo newton's method
    }
};

int main() {
    Solution2 s;
    std::cout << s.mySqrt(19) << std::endl;
    return 0;
}