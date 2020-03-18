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

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        return nums1.size() > nums2.size() ? findIntersect(nums1, nums2) : findIntersect(nums2, nums1);
    }
    
    vector<int> findIntersect(const vector<int>& nums1, const vector<int>& nums2) const {
        
        vector<int> result;
        
        if (nums1.size() == 0 || nums2.size() == 0) {
            return result;
        }
        
        int i = 0;
        while (i < nums1.size()) {
            if (nums1[i] == nums2[0]) {
                result.emplace_back(nums1[i]);
                std::cout << nums1[i] << std::endl;
                int m = i + 1;
                int n = 1;
                while (m < nums1.size() && n < nums2.size() && nums1[m] == nums2[n]) {
                    result.emplace_back(nums1[m]);
                    m++;
                    n++;
                }
                break;
            }
            i++;
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<int> a{2, 1}, b{1, 1};
    
    const auto r = s.findIntersect(a, b);

    std::cout << r.size() << ", " << r.at(0) << std::endl;

    return 0;
}