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
    void helper(TreeNode*node,TreeNode*&first,TreeNode*&second,TreeNode*&prev){
        if(!node)return;
        helper(node->left,first,second,prev);
        if(prev && node->val<prev->val){
            if(!first){
                first=prev;
            }
            second=node;
        }
        prev=node;
        // if(first && second)return;
        helper(node->right,first,second,prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode*prev=NULL;
        TreeNode*first=NULL;
        TreeNode*second=NULL;
        helper(root,first,second,prev);
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
    }
};