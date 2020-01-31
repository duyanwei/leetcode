/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-01-29
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> v2v, v2ind;
        for (size_t i = 0; i < nums.size(); i++) {
            const int val1 = nums.at(i);
            if (v2v.count(val1)) {
                return std::vector<int>{v2ind.at(v2v.at(val1)), i};
            } else {
                const int val2 = target - val1;
                v2v[val2] = val1;
                v2ind[val1] = i;
            }
        }
    }
};

int main() { return 0; }