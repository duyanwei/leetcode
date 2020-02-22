/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-02-22
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief explanation
 *
 * @details
 *     1. Solution2 Recursive method causes stack overflow for large array
 *     2. Solution1 adopt while loop, left && right
 *         a. be careful with boundary check
 *             i.e. > or >=, mid or mid + 1 or mid - 1
 *         b. corner case: nums = [3, 1], target = 1
 *         c. corner case: nums = [4, 5, 6, 7, 0, 1, 2], target = 3
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            const int mid = (left + right) / 2;  // mid can be equal to left
            if (target == nums.at(mid)) {
                return mid;
            }

            if (nums.at(left) <= nums.at(mid)) {  // please be noticed of (<=), = happens when left == mid
                if (target >= nums.at(left) && target < nums.at(mid)) {
                    right = mid - 1;  // mid - 1, not mid
                } else {
                    left = mid + 1;  // mid + 1, not mid
                }
            } else {
                if (target > nums.at(mid) && target <= nums.at(right)) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

/**
 * @brief solution2 recursion
 *
 * @SPACECOMPLEXITY xxx
 * @TIMECOMPLEXITY
 *
 */
class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        return search(nums, target, 0, nums.size() - 1);
    }

    int search(vector<int>& nums, int target, int left, int right) const {
        if (left > right) {
            return -1;
        }

        const int mid = (left + right) / 2;

        if (target == nums.at(mid)) {
            return mid;
        }

        if (nums.at(left) < nums.at(mid)) {
            if (target >= nums.at(left) && target <= nums.at(mid)) {
                return search(nums, target, left, mid - 1);
            } else {
                return search(nums, target, mid + 1, right);
            }
        } else {
            if (target >= nums.at(mid) && target <= nums.at(right)) {
                return search(nums, target, mid + 1, right);
            } else {
                return search(nums, target, left, mid - 1);
            }
        }
    }
};

int main() {
    //    // failure case 1
    //    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    //    const int target = 3;

    // failure case 2
    vector<int> nums{3, 1};
    const int target = 1;

    Solution s;
    std::cout << s.search(nums, target) << std::endl;
    return 0;
}