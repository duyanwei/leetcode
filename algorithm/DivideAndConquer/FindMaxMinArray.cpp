/**
 * @file FindMaxMinArray.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-09-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <assert.h>

#include <functional>
#include <iostream>
#include <vector>

/**
 * @brief introduction of DAC
 *
 * @link
 * https://www.geeksforgeeks.org/divide-and-conquer-algorithm-introduction/
 *
 * @verbatim
 * DAC(a, i, j)
 * {
 *     if (small(a, i, j))
 *         return solution(a, i, j)
 *     else
 *         m = divide(a, i, j)     // f1(n)
 *         b = DAC(a, i, mid)      // T(n/2)
 *         c = DAC(a, mid + 1, j)  // T(n/2)
 *         d = combine(a, c)       // f2(n)
 *     return(d)
 * }
 * // TimeComplexity: T(n) = aT(n/b) + f1(n) + f2(n)
 * @verbatim
 */

class Solution {
public:
    double run(const std::vector<double>& vec,
               int index,
               const std::function<bool(double, double)>& comp) const {
        assert(!vec.empty());
        if (vec.size() == 1u) {
            return vec[0];
        }
        if (index == vec.size() - 2u) {
            return comp(vec.at(index), vec.at(index + 1)) ? vec.at(index)
                                                          : vec.at(index + 1);
        }
        const double value = run(vec, index + 1, comp);
        return comp(vec.at(index), value) ? vec.at(index) : value;
    }
};

int main() {
    const std::vector<double> vec{120, 34, 54, 32, 58, 11, 90};
    const Solution s;
    const double vmin = s.run(vec, 0, std::less<double>());
    const double vmax = s.run(vec, 0, std::greater<double>());
    std::cout << "vmin: " << vmin << ", vmax: " << vmax << std::endl;
    return 0;
}