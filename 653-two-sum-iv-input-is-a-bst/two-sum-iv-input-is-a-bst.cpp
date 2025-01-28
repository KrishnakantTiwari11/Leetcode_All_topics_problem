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
    void inorder(TreeNode*root,vector<int>&arr){
        if(!root)return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>res;
        inorder(root,res);
        int n=res.size();
        int l=0,r=n-1;
        while(l<r){
            int temp=res[l]+res[r];
            if(temp==k)return true;
            if(temp>k){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
    }
};