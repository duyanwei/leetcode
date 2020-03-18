/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief reverse bits
 * @version 0.1
 * @date 2020-03-09
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

/**
 * @brief wrong solution!!!
 *
 * @failure case
 * input: 00000010100101000001111010011100
 * output:    15065253 (00000000111001011110000010100101)
 * expected: 964176192 (00111001011110000010100101000000)
 */

class WrongSolution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        while (n > 0) {
            result <<= 1;
            result += (n & 1);
            n >>= 1;
        }
        return result;
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (uint32_t i = 0u; i < 32u; i++) {
            // becareful with n turns to zero while it still has many
            // "0"s bits
            result <<= 1;
            result += (n & 1);
            n >>= 1;
        }
        return result;
    }
};

int main() {
    Solution s;

    const uint32_t n = 11u;
    std::cout << s.reverseBits(n) << std::endl;
    return 0;
}