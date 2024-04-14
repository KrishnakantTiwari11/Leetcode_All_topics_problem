class Solution {
public:
    void inorder(TreeNode* root,int & ans){
        if(!root)return;

        inorder(root->left,ans);
        if(root->left && !root->left->left && !root->left->right)ans+=root->left->val;
        inorder(root->right,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        inorder(root,ans);
        return ans;
    }
};