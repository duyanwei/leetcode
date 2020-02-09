/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-02-02
 *
 * @copyright Copyright (c) 2020
 *
 */

/**
 * @brief
 * @ref
https://leetcode.com/problems/remove-duplicates-from-sorted-array/solution/
 *
 * Approach 1: Two Pointers
 * Algorithm
 * Since the array is already sorted, we can keep two pointers i and j, where i
 * is the slow-runner while j is the fast-runner. As long as nums[i] ==
 * nums[j], we increment j to skip the duplicate. When we encounter nums[j] !=
 * nums[i], the duplicate run has ended so we must copy its value to nums[i+1].
 * i is then incremented and we repeat the same process again until j reaches
 * the end of array.
 */
