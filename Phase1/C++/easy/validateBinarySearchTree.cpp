#include <iostream>
#include <limits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to validate the binary search tree
bool validateBST(TreeNode* node, long long minVal, long long maxVal) {
    // Base case: If node is null, it is a valid BST
    if (node == nullptr) {
        return true;
    }

    // Check if the current node violates the BST property
    if (node->val <= minVal || node->val >= maxVal) {
        return false;
    }

    // Recursively check the left and right subtrees
    return validateBST(node->left, minVal, node->val) &&
           validateBST(node->right, node->val, maxVal);
}

// Main function to validate if the binary tree is a BST
bool isValidBST(TreeNode* root) {
    return validateBST(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
}

// Example usage
int main() {
    // Example 1: Tree [2, 1, 3]
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    cout << "Is valid BST (Example 1): " << (isValidBST(root1) ? "True" : "False") << endl;

    // Example 2: Tree [5, 1, 4, null, null, 3, 6]
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);

    cout << "Is valid BST (Example 2): " << (isValidBST(root2) ? "True" : "False") << endl;

    return 0;
}



