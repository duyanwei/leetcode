/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-03-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 
 * 
 * @TIMECOMPLEXITY O(n)
 * @SPACECOMPLEXITY O(n)
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        unordered_set<int> data;
        for (const auto & val : nums) {
            if (data.count(val)) {
                continue;
            }
            data.insert(val);
        }
        
        vector<int> result;
        for (size_t i = 1; i <= nums.size(); i++) {
            if (data.count(i)) {
                continue;
            }
            result.push_back(i);
        }
        return result;
    }
};

class Solution2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums.at(i) == -1) {
                continue;
            }
            int start = nums.at(i) - 1;
            while (nums.at(start) != -1) {
                int tmp = nums.at(start) - 1;
                nums.at(start) = -1;
                start = tmp;
            }
        }
        
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums.at(i) != -1) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};


int main()
{
    Solution2 s;
    std::vector<int> nums{4,3,2,7,8,2,3,1};
    s.findDisappearedNumbers(nums);
    return 0;
}