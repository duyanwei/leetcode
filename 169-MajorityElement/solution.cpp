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

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief brute force, sorting
 *
 * @TIMECOMPLEXITY nlog(n)
 *
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums.at(nums.size() / 2);
    }
};

/**
 * @brief Boyer-Moore Voting Algorithm
 *
 * @details https://www.cnblogs.com/xiaolovewei/p/8085969.html
 *
 */
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ele = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                ele = nums.at(i);
                count++;
            } else {
                if (nums.at(i) == ele) {
                    count++;
                } else {
                    count--;
                }
            }
            return ele;
        }
    };