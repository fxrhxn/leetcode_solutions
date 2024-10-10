#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        // If the tree is empty, return null
        if (!root) {
            return nullptr;
        }

        // Recursively prune the left and right subtrees
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        // If both left and right subtrees are pruned (null) and the current node is 0, prune this node too
        if (root->val == 0 && !root->left && !root->right) {
            return nullptr; // Prune the current node
        }

        return root; // Return the pruned tree
    }
};

// Helper function to print the binary tree in level order
void printTree(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Solution solution;

    // Example 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(0);
    root1->right = new TreeNode(0);
    root1->right->right = new TreeNode(1);

    cout << "Example 1 Output: ";
    TreeNode* prunedTree1 = solution.pruneTree(root1);
    printTree(prunedTree1); // Output should be 1 null 0 null 1
    cout << endl;

    // Example 2
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(0);
    root2->left->right = new TreeNode(0);
    root2->right->right = new TreeNode(1);

    cout << "Example 2 Output: ";
    TreeNode* prunedTree2 = solution.pruneTree(root2);
    printTree(prunedTree2); // Output should be 1 null 1 null 1
    cout << endl;

    // Example 3
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(1);
    root3->right = new TreeNode(0);
    root3->left->left = new TreeNode(1);
    root3->left->right = new TreeNode(1);
    root3->right->left = new TreeNode(0);
    root3->right->right = new TreeNode(1);

    cout << "Example 3 Output: ";
    TreeNode* prunedTree3 = solution.pruneTree(root3);
    printTree(prunedTree3); // Output should be 1 1 0 1 1 null 1
    cout << endl;

    // Cleanup memory (not shown for brevity)

    return 0;
}
