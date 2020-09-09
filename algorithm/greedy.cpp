/**
 * @file greedy.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-07-29
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> run(const std::vector<double>& weights,
                         const std::vector<double>& price,
                         const double value) const {
        std::vector<int> result;
        return result;
    }

private:

    void dp()
    {
        
    }
};

int main() {
    const std::vector<double> weights{35, 30, 60, 50, 40, 10, 25};
    const std::vector<double> price{10, 40, 30, 50, 35, 40, 30};

    const double value = 100;

    Solution s;
    const std::vector<int> indices = s.run(weights, price, value);

    for (size_t i = 0u; i < indices.size(); i++) {
        std::cout << indices.at(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}
