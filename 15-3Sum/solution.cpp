/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-02-09
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief brute-force
 *
 * @TimeComplexity O(3)
 * @SpaceComplexity O(1)
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                for (size_t k = j + 1; k < nums.size(); k++) {
                    if (nums.at(i) + nums.at(j) + nums.at(k) == 0) {
                        vector<int> r{nums.at(i), nums.at(j), nums.at(k)};
                        if (exists(result, r)) {
                            continue;
                        }
                        result.emplace_back(r);
                    }
                }
            }
        }
        return result;
    }

    bool exists(const vector<vector<int>>& buffer,
                const vector<int>& element) const {
        for (size_t i = 0; i < buffer.size(); i++) {
            size_t j = 0;
            for (; j < element.size(); j++) {
                if (buffer[i][j] != element.at(j)) {
                    break;
                }
            }

            if (j == element.size()) {
                return true;
            }
        }
        return false;
    }
};

/**
 * @brief similar to 2-sum
 *
 * @time complexity worst case O(n^2), best case O(nlog(n))
 */

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        if (nums.size() < 3) {
            return results;
        }
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 2u; i++) {
            const int value = nums.at(i);
            if (i != 0 && nums.at(i) == nums.at(i - 1)) {
                continue;
            }
            size_t left = i + 1;
            size_t right = nums.size() - 1;
            while (left < right) {
                if (nums.at(left) + nums.at(right) == -value) {
                    vector<int> r{value, nums.at(left), nums.at(right)};
                    results.emplace_back(r);
                    left++;
                    while (left < right && nums.at(left) == nums.at(left - 1)) {
                        left++;
                    }
                } else if (nums.at(left) + nums.at(right) < -value) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return results;
    }
};

int main() {
    Solution ss;
    return 0;
}