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
    void preorder(vector<TreeNode*>&arr,TreeNode*node){
         if(!node)return;
         arr.push_back(node);
         preorder(arr,node->left);
         preorder(arr,node->right);
    }
    void flatten(TreeNode* root) {
        if(!root)return;
        vector<TreeNode*>pre;
        preorder(pre,root);
        int n=pre.size();
        for(int i=0;i<n-1;i++){
            pre[i]->right=pre[i+1];
            pre[i]->left=NULL;
        }
        pre[n-1]->right=NULL;
        pre[n-1]->left=NULL;
    }
};