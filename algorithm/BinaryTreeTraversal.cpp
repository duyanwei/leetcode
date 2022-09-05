/**
 * @file BinaryTreeTraversal.cpp
 * @author Yanwei Du (yanwei.du@gatech.edu)
 * @brief None
 * @version 0.1
 * @date 09-05-2022
 * @copyright Copyright (c) 2022
 */

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

/**
 * @brief define tree node
 *
 * @link https://www.geeksforgeeks.org/level-order-tree-traversal/
 */
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    /**
     * @brief Construct a new Tree Node object
     *
     * @param _value
     */
    TreeNode(int _value) : value(_value), left(nullptr), right(nullptr) {}
};

/**
 * @brief construt an example tree node
 *
 * @details
 *            1
 *           /  \
 *          2    3
 *         / \
 *        4   5
 * @verbatim
 * Depth First Traversals:
 * (a) Inorder (Left, Root, Right) : 4 2 5 1 3
 * (b) Preorder (Root, Left, Right) : 1 2 4 5 3
 * (c) Postorder (Left, Right, Root) : 4 5 2 3 1
 * Breadth-First or Level Order Traversal: 1 2 3 4 5
 * @verbatim
 * @return TreeNode*
 */
TreeNode* constructTree() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

/**
 * @brief pre order iterative  (Root, Left, Right)
 *
 * @param root
 */
void preOrderIterative(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::stack<TreeNode*> buffer;
    buffer.push(root);
    while (!buffer.empty()) {
        TreeNode* cur = buffer.top();
        buffer.pop();
        std::cout << cur->value << ", ";
        if (cur->right != nullptr) {
            buffer.push(cur->right);
        }
        if (cur->left != nullptr) {
            buffer.push(cur->left);
        }
    }
}

/**
 * @brief
 *
 * @param root
 */
void preOrderRecursive(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->value << ", ";
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);
}

/**
 * @brief (Left, Root, Right)
 *
 * @param root
 */
void inOrderIterative(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::stack<TreeNode*> buffer;
    TreeNode* node = root;
    // while (node || !buffer.empty()) {
    //     while (node) {
    //         buffer.push(node);
    //         node = node->left;
    //     }
    //     node = buffer.top();
    //     buffer.pop();
    //     std::cout << node->value << ", ";
    //     node = node->right;
    // }
    while (node) {
        buffer.push(node);
        node = node->left;
    }
    while (!buffer.empty()) {
        node = buffer.top();
        buffer.pop();
        std::cout << node->value << ", ";
        if (node->right != nullptr) {
            buffer.push(node->right);
        }
    }
}

/**
 * @brief
 *
 * @param root
 */
void inOrderRecursive(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrderRecursive(root->left);
    std::cout << root->value << ", ";
    inOrderRecursive(root->right);
}

/**
 * @brief (Left, Right, Root)
 *
 * @param root
 */
void postOrderIterative(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::vector<int> result;
    std::stack<TreeNode*> buffer;
    buffer.push(root);
    while (!buffer.empty()) {
        TreeNode* node = buffer.top();
        buffer.pop();
        result.emplace_back(node->value);
        if (node->left != nullptr) {
            buffer.push(node->left);
        }
        if (node->right != nullptr) {
            buffer.push(node->right);
        }
    }

    for (int i = result.size() - 1u; i >= 0; i--) {
        std::cout << result.at(i) << ", ";
    }
}

/**
 * @brief
 *
 * @param root
 */
void postOrderRecursive(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    std::cout << root->value << ", ";
}

/**
 * @brief BFS, from left to right
 *
 * @param root
 */
void BFS(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::queue<TreeNode*> buffer;
    buffer.push(root);
    while (!buffer.empty()) {
        TreeNode* node = buffer.front();
        std::cout << node->value << ", ";
        buffer.pop();
        if (node->left != nullptr) {
            buffer.push(node->left);
        }
        if (node->right != nullptr) {
            buffer.push(node->right);
        }
    }
}

/**
 * @brief main
 *
 * @return int
 */
int main() {
    TreeNode* root = constructTree();
    std::cout << "preOrderIterative = ";
    preOrderIterative(root);
    std::cout << "\n";
    std::cout << "preOrderRecursive = ";
    preOrderRecursive(root);
    std::cout << "\n";
    std::cout << "inOrderIterative = ";
    inOrderIterative(root);
    std::cout << "\n";
    std::cout << "inOrderRecursive = ";
    inOrderRecursive(root);
    std::cout << "\n";
    std::cout << "postOrderIterative = ";
    postOrderIterative(root);
    std::cout << "\n";
    std::cout << "postOrderRecursive = ";
    postOrderRecursive(root);
    std::cout << "\n";
    std::cout << "BFS = ";
    BFS(root);
    std::cout << std::endl;

    return 0;
}
