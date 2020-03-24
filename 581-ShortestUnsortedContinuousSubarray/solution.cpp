/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-03-24
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

/**
 * @brief brute-force
 *
 * @TIMECOMPLEXITY O(n^2) time limit exceeding
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int r = 0;
        int l = nums.size();

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[i]) {
                    r = max(r, j);
                    l = min(l, i);
                }
            }
        }

        return r < l ? 0 : r - l + 1;
    }
};

/**
 * @brief sort and loop
 *
 * @TIMECOMPLEXITY nlog(n)
 */
class Solution2 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int r = 0;
        int l = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            if (sorted[i] != nums[i]) {
                r = max(r, i);
                l = min(l, i);
            }
        }

        return r < l ? 0 : r - l + 1;
    }
};

/**
 * @brief using stack
 *
 * @TIMECOMPLEXITY O(n)
 * @SPACECOMPLEXITY 0(n)
 *
 */
class Solution3 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = nums.size();
        int r = 0;

        stack<int> data;

        for (int i = 0; i < nums.size(); i++) {
            while (!data.empty() && nums.at(data.top()) > nums.at(i)) {
                l = min(l, data.top());
                data.pop();
            }
            data.push(i);
        }

        while (!data.empty()) {
            data.pop();
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!data.empty() && nums.at(data.top()) < nums.at(i)) {
                r = max(r, data.top());
                data.pop();
            }
            data.push(i);
        }

        return r < l ? 0 : r - l + 1;
    }
};

/**
 * @brief 4 for-loops
 *
 * @TIMECOMPLEXITY O(n)
 * @SPACECOMPLEXITY O(1)
 */
class Solution4 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int min_val = INT_MAX;
        int max_val = INT_MIN;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums.at(i) > nums.at(i + 1)) {
                min_val = min(min_val, nums.at(i + 1));
            }
        }

        int l = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) > min_val) {
                l = i;
                break;
            }
        }

        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums.at(i) < nums.at(i - 1)) {
                max_val = max(max_val, nums.at(i - 1));
            }
        }

        int r = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums.at(i) < max_val) {
                r = i;
                break;
            }
        }
        return r > l ? r - l + 1 : 0;
    }
};