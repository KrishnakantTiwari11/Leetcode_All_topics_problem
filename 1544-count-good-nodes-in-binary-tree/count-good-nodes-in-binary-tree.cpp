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
    void helper(TreeNode*node,int & count,int prev_max){
        if(!node)return;
        if(node->val>=prev_max){
            count++;
            prev_max=node->val;
        }
        helper(node->left,count,prev_max);
        helper(node->right,count,prev_max);
    }
    int goodNodes(TreeNode* root) {
        if(!root->left && !root->right)return 1;
        int ans=0;
        helper(root,ans,root->val);
        return ans;
    }
};