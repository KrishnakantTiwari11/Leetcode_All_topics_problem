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
    bool inorder(TreeNode*node,int & ans,int & k){
        if(!node)return true;
        if(!inorder(node->left,ans,k))return false;
        k--;
        if(k==0){
            ans=node->val;
            return false;
        }
        if(!inorder(node->right,ans,k))return false;
        return true;
    }
    int kthSmallest(TreeNode* root, int k) {
        int res=0;
        inorder(root,res,k);
        return res;
    }
};