/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-03-24
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>

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

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        getDepth(root, result);
        return result;
    }

private:
    int getDepth(TreeNode* root, int& result) {
        if (root == NULL) {
            return 0;
        }

        int l = getDepth(root->left, result);
        int r = getDepth(root->right, result);
        // std::cout << root->val << ", " << "l =" << l << ", r = " << r << ", ";
        // std::cout << result << std::endl;
        result = max(result, l + r);
        return max(l, r) + 1;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    {
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
    }

    Solution s;
    s.diameterOfBinaryTree(root);

    return 0;
}