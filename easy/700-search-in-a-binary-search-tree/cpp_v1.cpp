// Pushed: 2026-10-20 22:21:22 UTC
// Difficulty: Easy
// Runtime: 0 ms
// Memory: 35.5 MB

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == val) {
            return root;
        }

        if (val < root->val) {
            return searchBST(root->left, val);
        }

        return searchBST(root->right, val);
    }
};