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
 * @brief brute force method
 *
 * @TIMECOMPLEXITY O(2^n), size of tree would be 2^n
 * @SPACECOMPLEXITY O(n), depth of tree would be n
 *
 */
class Solution {
public:
    int climbStairs(int n) {
        int result = 0;
        backtracking(0, n, result);
        return result;
    }

    void backtracking(const int cur, const int n, int& result) const {
        if (cur == n) {
            result++;
        } else if (cur > n) {
            return;
        } else {
            backtracking(cur + 1, n, result);
            backtracking(cur + 2, n, result);
        }
    }
};

/**
 * @brief dynamic programming
 *
 * Algorithm
 * As we can see this problem can be broken into subproblems, and it contains
 * the optimal substructure property i.e. its optimal solution can be
 * constructed efficiently from optimal solutions of its subproblems, we can
 * use dynamic programming to solve this problem.
 * One can reach i^{th} step in one of the two ways:
 *     Taking a single step from (i-1)^{th} step.
 *     Taking a step of 22 from (i-2)^{th} step.
 *     So, the total number of ways to reach i^{th} is equal to sum of ways of
 *     reaching (i-1)^{th} step and ways of reaching (i-2)^{th} step.
 * Let dp[i]dp[i] denotes the number of ways to reach on i^{th} step:
 *     dp[i]=dp[i-1]+dp[i-2] dp[i]=dp[i−1]+dp[i−2]
 */
class Solution2 {
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }
        std::vector<int> dp(n);
        dp[0] = 1;
        dp[1] = 2;
        for (size_t i = 2u; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};

int main() {
    Solution2 s;
    std::cout << s.climbStairs(44) << std::endl;
    return 0;
}