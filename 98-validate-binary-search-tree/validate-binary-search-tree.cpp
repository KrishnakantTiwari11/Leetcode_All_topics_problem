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
    void inorder(TreeNode*node,vector<int>&arr){
        if(!node)return;
        inorder(node->left,arr);
        arr.push_back(node->val);
        inorder(node->right,arr);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>res;
        inorder(root,res);
        int n=res.size();
        // int prev_max=res[0];
        for(int i=1;i<n;i++){
            if(res[i]<=res[i-1])return false;
        }
        return true;
    }
};