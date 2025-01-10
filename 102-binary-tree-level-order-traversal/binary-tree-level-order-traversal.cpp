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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while (!q.empty()) {
            vector<int> temp;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* temp_node = q.front();
                q.pop();
                temp.push_back(temp_node->val);
                if (temp_node->left)
                    q.push(temp_node->left);
                if (temp_node->right)
                    q.push(temp_node->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};