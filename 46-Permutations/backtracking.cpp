/**
 * @file backtracking.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-02-24
 *
 * @copyright Copyright (c) 2020
 *
 */

/**
 * @brief an introduction of backtracking
 *
 * @details https://blog.csdn.net/varyall/article/details/81160356
 * @details
 *     https://www.cis.upenn.edu/~matuszek/cit594-2012/Pages/backtracking.html
 *
 * 1. backtracking can use recursion or stack
 * 2. cases that you should consider using backtracking
 *    a. find a path to success
 *    b. find all paths to success
 *    c. find the best path to success
 * 3. this procedure is repeated over and over until you reach a final state.
 *    if you made a good sequence of choices, your final state is a goal state,
 *    if you didn't, it isn't.
 *
 *
 */

// pseudo code 1
bool solve(Node n) {
    if
        n is a leaf node {
            if
                the leaf is a good node : return true;
            else
                return false;
        }
    else {
        for
            each child c of n {
                if
                    solve(c) succeeds : return true;
            }
        return true;
    }
}

// pseudo code 2
global variable count = 0;
void solve(Node n) {
    if
        n is a leaf node {
            if
                the leaf is a good node, count++, return;
            else
                return;
        }
    else {
        for
            each child c of n { solve(c) }
    }
}

// pseudo code 3
void solve(Node n) {
    if
        n is a leaf node {
            if
                the leaf is a goal node, update best result, return;
            else
                return;
        }
    else {
        for
            each child c of n { solve(c) }
    }
}