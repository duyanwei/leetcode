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

#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @brief solution
 *
 * @details half and half
 * @concept height-balanced search tree (height difference never differ than 1)
 *
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, (int)nums.size() - 1);
    }

    TreeNode* buildTree(const std::vector<int>& nums,
                        int left,
                        int right) const {
        if (left > right) {
            return NULL;
        }

        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums.at(mid));
        node->left = buildTree(nums, left, mid - 1);
        node->right = buildTree(nums, mid + 1, right);
        return node;
    }
};