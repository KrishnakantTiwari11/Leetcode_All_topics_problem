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
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            TreeNode* curr = q.front().first;
            int currInd = q.front().second;
            q.pop();
            if(res.size()==currInd){
                res.push_back({});
            }
            res[currInd].push_back(curr->val);
            if (curr->left) {
                q.push({curr->left, currInd + 1});
            }
            if (curr->right) {
                q.push({curr->right, currInd + 1});
            }
        }
        return res;
    }
};