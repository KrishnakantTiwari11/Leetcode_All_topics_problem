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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        stack<vector<int>>s;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            for (int i = 0; i < n; i++) {
                TreeNode*node=q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
           s.push(level);
        }
        while(!s.empty()){
            vector<int>temp=s.top();
            s.pop();
            res.push_back(temp);
        }
        return res;
    }
};