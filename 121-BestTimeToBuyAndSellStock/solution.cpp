/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-03-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int min_profit = prices[0];
        int result = 0;
        for (size_t i = 1; i < prices.size(); i++) {
            result = result < (prices[i] - min_profit) ? (prices[i] - min_profit) : result;
            min_profit = min_profit < prices[i] ? min_profit : prices[i];
        }
        return result;
    }
};

int main() {
    return 0;
}