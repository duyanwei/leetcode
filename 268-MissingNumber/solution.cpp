/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-03-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int value = nums.at(0) ^ 0;
        for (size_t i = 1; i < nums.size(); i++) {
            value = value ^ (i ^ nums.at(i));
        }
        value = value ^ nums.size();
        return value;
    }
};

class Solution2{
public:
    int missingNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size(); i++) {
            if (i != nums.at(i)) {
                return i;
            }
        }
        return -1;
    }
};

