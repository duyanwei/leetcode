#include <iostream>
#include <stack>
#include <vector>

/**
 * @brief define tree node
 *
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
 *            3
 *           /  \
 *          9   20
 *              / \
 *             15  7
 * @return TreeNode*
 */
TreeNode* constructTree() {
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

/**
 * @brief pre order iterative
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
        if (cur->left != nullptr) {
            buffer.push(cur->right);
        }
        if (cur->right != nullptr) {
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
 * @brief
 *
 * @param root
 */
void inOrderIterative(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::stack<TreeNode*> buffer;
    TreeNode* node = root;
    while (node || !buffer.empty()) {
        while (node) {
            buffer.push(node);
            node = node->left;
        }
        node = buffer.top();
        buffer.pop();
        std::cout << node->value << ", ";
        node = node->right;
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
 * @brief
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
    std::cout << std::endl;

    return 0;
}
