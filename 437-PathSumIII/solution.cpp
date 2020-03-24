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


/**
 * @brief !!! two recursion !!!
 * 
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int result = 0;
        dfs(root, sum, result);
        
        if (root != NULL) {
            result += pathSum(root->left, sum) + pathSum(root->right, sum);
        }
        return result;
    }
    
private:
    void dfs(TreeNode* root, int sum, int& result) {
        if (root == NULL) {
            return;
        }
        
        if (root->val == sum) {
            result++;
        }
        dfs(root->left, sum - root->val, result);
        dfs(root->right, sum - root->val, result);
    }
};