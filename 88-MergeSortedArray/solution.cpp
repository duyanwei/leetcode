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

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief solution
 *
 * @details this is a very interesting solution. as nums1 has enough empty
 *          space at rear position, we should start from there instead of front
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1.at(i) > nums2.at(j)) {
                nums1.at(k--) = nums1.at(i--);
            } else {
                nums1.at(k--) = nums2.at(j--);
            }
        }

        if (i < 0 && j >= 0) {
            while (j >= 0) {
                nums1.at(k--) = nums2.at(j--);
            }
        }
        if (j < 0 && i >= 0) {
            while (i >= 0) {
                nums1.at(k--) = nums1.at(i--);
            }
        }
    }
};