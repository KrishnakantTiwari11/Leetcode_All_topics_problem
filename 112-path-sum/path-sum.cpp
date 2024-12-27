/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>res;
        while(!q.empty()){
            int n=q.size();
            vector<int>level;
            for(int i=0;i<n;i++){
                TreeNode*node=q.front();
                q.pop();
                if(!node->left && !node->right){
                    if(node->val==targetSum)return true;
                }
                level.push_back(node->val);
                if(node->left){
                    node->left->val+=node->val;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val+=node->val;
                    q.push(node->right);
                }
            }
            res.push_back(level);
        }
        return false;
    }
};