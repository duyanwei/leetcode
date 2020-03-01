/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-02-29
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief dynamic programming
 *
 * @SPACECOMPLEXITY O(n)
 * @TIMECOMPLEXITY 0(n)
 *
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::vector<int> dp(nums.size());
        dp[0] = nums.at(0);
        for (size_t i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums.at(i), nums.at(i));
        }
        return *max_element(dp.begin(), dp.end());
    }
};

/**
 * @brief
 *
 * @SPACECOMPLEXITY constant
 * @TIMECOMPLEXITY constant
 */
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = INT_MAX;
        for (size_t i = 1; i < nums.size(); i++) {
            sum += nums.at(i);
            if (sum > max) {
                max = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return max;
    }
};

int main() { return 0; }