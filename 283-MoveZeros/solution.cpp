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

#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums.at(i) == 0) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums.at(j) == 0) {
                        continue;
                    }
                    std::swap(nums.at(i), nums.at(j));
                    break;
                }
            }
        }
    }
};


class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        size_t last_no_zero_index = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            // two pointers
            if (nums.at(i) != 0) {
                nums.at(last_no_zero_index++) = nums.at(i);
            }
        }

        for (size_t i = last_no_zero_index; i < nums.size(); i++) {
            nums.at(i) = 0;
        }
    }
};