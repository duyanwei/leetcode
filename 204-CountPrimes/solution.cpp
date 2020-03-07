/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-03-05
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int countPrimes(int n) {
        int m = n - 1;
        int num = 0;
        while (m > 2) {
            int i = 2;
            for (; i * i < m; i++) {  // loop from 2 to sqrt(n), not n / 2 !!!
                if (m % i == 0) {
                    break;
                }
            }
            if (i * i > m) {
                num++;
            }
            m--;
        }
        if (m == 2) {
            num++;
        }
        return num;
    }
};

/**
 * @brief
 *
 * @ref: https://www.cnblogs.com/grandyang/p/4462810.html
 * 我们从2开始遍历到根号n，先找到第一个质数2，然后将其所有的倍数全部标记出来，
 * 然后到下一个质数3，标记其所有倍数，一次类推，直到根号n，此时数组中未被标记的数字就是质数。
 * 我们需要一个 n-1 长度的 bool 型数组来记录每个数字是否被标记，长度为 n-1
 * 的原因是题目说是小于n的质数个数，并不包括n。然后来实现埃拉托斯特尼筛法，难度并不是很大，
 * 代码如下所示：
 */
class Solution2 {
public:
    int countPrimes(int n) {
        int num = 0;
        std::vector<int> primes(n, true);
        for (int i = 2; i < n; i++) {
            if (!primes.at(i)) {
                continue;
            }
            num++;
            for (int j = 2; i * j < n; j++) {
                primes.at(i * j) = false;
            }
        }
        return num;
    }
};

int main() {
    Solution2 s;
    std::cout << s.countPrimes(499979) << std::endl;
    return 0;
}