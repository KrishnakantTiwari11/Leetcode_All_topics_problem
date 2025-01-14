/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        if (!root->left && !root->right)
            return true;
        if (!root->left || !root->right)
            return false;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                pair<TreeNode*, TreeNode*> node = q.front();
                q.pop();
                if (node.first->val != node.second->val)
                    return false;
                if (node.first->left && !node.second->right)
                    return false;
                if (!node.first->left && node.second->right)
                    return false;
                if (node.first->right && !node.second->left)
                    return false;
                if (!node.first->right && node.second->left)
                    return false;

                if (node.first->left && node.second->right)
                    q.push({node.first->left, node.second->right});
                if (node.first->right && node.second->left)
                    q.push({node.first->right, node.second->left});
            }
        }
        return true;
    }
};