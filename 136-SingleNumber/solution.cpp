/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-03-01
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief XOR c++
 *
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            result ^= nums.at(i);
        }
        return result;
    }
};