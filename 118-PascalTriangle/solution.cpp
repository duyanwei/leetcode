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

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 1; i <= numRows; i++) {
            vector<int> nums(i, 1);
            for (int j = 1; j < i - 1; j++) {
                nums.at(j) = result[i - 2][j - 1] + result[i - 2][j];
            }
            result.push_back(nums);
        }
        return result;
    }
};