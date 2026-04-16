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
    vector<TreeNode*> rootToNodePath(TreeNode* node, TreeNode* data) {
        if (node == nullptr)
            return {};

        if (node->val == data->val) {
            return {node};
        }

        vector<TreeNode*> left = rootToNodePath(node->left, data);
        if (!left.empty()) {
            left.push_back(node);
            return left;
        }

        vector<TreeNode*> right = rootToNodePath(node->right, data);
        if (!right.empty()) {
            right.push_back(node);
            return right;
        }

        return {};
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // find root to node path of both nodes
        vector<TreeNode*> path1 = rootToNodePath(root, p);
        vector<TreeNode*> path2 = rootToNodePath(root, q);

        // find common ancestor
        TreeNode* ans = nullptr;
        int i = path1.size() - 1;
        int j = path2.size() - 1;

        while (i >= 0 && j >= 0) {
            if (path1[i]->val == path2[j]->val) {
                ans = path1[i];
            } else {
                break;
            }
            i--;
            j--;
        }

        return ans;
    }
};