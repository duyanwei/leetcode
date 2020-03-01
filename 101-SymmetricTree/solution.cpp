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

// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        return isEqual(root->left, root->right);
    }

    bool isEqual(TreeNode* left, TreeNode* right) const {
        if (left == NULL && right == NULL) {
            return true;
        } else if (left == NULL || right == NULL || left->val != right->val) {
            return false;
        }
        return isEqual(left->left, right->right) &&
               isEqual(right->left, left->right);
    }
};