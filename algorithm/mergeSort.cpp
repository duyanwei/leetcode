/**
 * @file mergeSort.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-10-13
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <vector>

/**
 * @brief
 *
 * @TIMECOMPLEXITY O(nlog(n))
 * @SPACECOMPLEXITY O(1)
 */
class Solution {
public:
    /**
     * @brief
     *
     * @param vec
     */
    void run(std::vector<int>& vec) { mergeSort(vec, 0, vec.size() - 1); }

private:
    void merge(std::vector<int>& vec, int left, int mid, int right) {
        std::vector<int> lvec(vec.begin() + left, vec.begin() + mid + 1);
        std::vector<int> rvec(vec.begin() + mid + 1, vec.begin() + right + 1);

        int l = 0;
        int r = 0;

        while (l < lvec.size() && r < rvec.size()) {
            if (lvec.at(l) < rvec.at(r)) {
                vec.at(left++) = lvec.at(l);
                l++;
            } else {
                vec.at(left++) = rvec.at(r);
                r++;
            }
        }

        if (l == lvec.size()) {
            while (r < rvec.size()) {
                vec.at(left++) = rvec.at(r++);
            }
        }

        if (r == rvec.size()) {
            while (l < lvec.size()) {
                vec.at(left++) = lvec.at(l++);
            }
        }
    }

    void mergeSort(std::vector<int>& vec, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;

            mergeSort(vec, left, mid);
            mergeSort(vec, mid + 1, right);

            merge(vec, left, mid, right);
        }
    }
};

int main() {
    std::vector<int> vec{1, 6, 3, 4, 5, 2};

    for (size_t i = 0; i < 6; i++) {
        std::cout << vec[i] << "\t";
    }
    std::cout << "\n";

    Solution s;
    s.run(vec);

    for (size_t i = 0; i < 6; i++) {
        std::cout << vec[i] << "\t";
    }
    std::cout << "\n";
    return 0;
}
