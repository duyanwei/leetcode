/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-02-22
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <array>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief brute-force solution
 *
 * @TIMECOMPLEXITY O(1) constant
 * @SPACECOMPLEXITY O(1) constant
 *
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check row
        for (size_t i = 0; i < board.size(); i++) {
            vector<bool> flags(9, false);
            for (size_t j = 0; j < board[0].size(); j++) {
                const int index = board[i][j] - '1';
                if (index >= 0 && index < 9) {
                    if (flags.at(index)) {
                        return false;
                    } else {
                        flags.at(index) = true;
                    }
                }
            }
        }

        // check col
        for (size_t i = 0; i < board.size(); i++) {
            vector<bool> flags(9, false);
            for (size_t j = 0; j < board[0].size(); j++) {
                const int index = board[j][i] - '1';
                if (index >= 0 && index < 9) {
                    if (flags.at(index)) {
                        return false;
                    } else {
                        flags.at(index) = true;
                    }
                }
            }
        }

        // check block
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                vector<bool> flags(9, false);
                const int row = i * 3;
                const int col = j * 3;
                for (size_t k = 0; k < 3; k++) {
                    for (size_t l = 0; l < 3; l++) {
                        const int index = board[row + k][col + l] - '1';
                        if (index >= 0 && index < 9) {
                            if (flags.at(index)) {
                                return false;
                            } else {
                                flags.at(index) = true;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};

/**
 * @brief merge three different checks into one while using 9x9 bitset(0) matrix
 *
 */
class Solution2 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<bitset<9>, 9> r, c, b;
        // check row, col and block
        for (size_t i = 0; i < board.size(); i++) {
            vector<bool> flags(9, false);
            for (size_t j = 0; j < board[0].size(); j++) {
                const int index = board[i][j] - '1';
                if (index >= 0 && index < 9) {
                    const int k = (i / 3) * 3 + j / 3;
                    if (r[i][index] || c[j][index] || b[k][index]) {
                        return false;
                    } else {
                        r[i][index] = 1;
                        c[j][index] = 1;
                        b[k][index] = 1;
                    }
                }
            }
        }
        return true;
    }
};

/**
 * @brief explain of bitset
 *
 * C++的 bitset 在 bitset
 * 头文件中，它是一种类似数组的结构，它的每一个元素只能是０或１，
 * 每个元素仅用１bit空间。
 *
 * bitset<4> bitset1;　　//无参构造，长度为４，默认每一位为０
 * bitset<8> bitset2(12);　　//长度为８，二进制保存，前面用０补充
 * string s = "100101";
 * bitset<10> bitset3(s);　　//长度为10，前面用０补充
 *
 * char s2[] = "10101";
 * bitset<13> bitset4(s2);　　//长度为13，前面用０补充
 *
 * cout << bitset1 << endl;　　//0000
 * cout << bitset2 << endl;　　//00001100
 * cout << bitset3 << endl;　　//0000100101
 * cout << bitset4 << endl;　　//0000000010101
 */