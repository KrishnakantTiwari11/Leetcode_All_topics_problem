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
    void helper(TreeNode*node,vector<int>&temp,int  value){
        if(!node)return;
        value=value*10+node->val;
        if(!node->left && !node->right){
            temp.push_back(value);
            return;
        }
        helper(node->left,temp,value);
        helper(node->right,temp,value);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)return {};
        vector<int>temp;
        int value=0;
        helper(root,temp,value);
        int ans=0;
        for(int i=0;i<temp.size();i++){
             ans+=temp[i];
        }
        return ans;
     }
};