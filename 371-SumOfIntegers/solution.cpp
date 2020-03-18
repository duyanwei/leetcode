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


/**
 * @brief 
 * 
 * @ref https://www.cnblogs.com/dyzhao-blog/p/5662891.html
 * 
 * @details add by bit (XOR ^), move bit (AND &, << 1)
 */

class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int c = a ^ b;
            b =(unsigned int) (a & b) << 1; 
            // (unsigned int) is necessary, otherwise it fails with negative value
            a = c;
        }
        return a;
    }
};