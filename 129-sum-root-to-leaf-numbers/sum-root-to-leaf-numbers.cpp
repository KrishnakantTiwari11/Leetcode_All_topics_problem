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
    int helper(TreeNode*node,int  value){
        if(!node)return 0;
        value=value*10+node->val;
        if(!node->left && !node->right){
            return value;
        }
        int left=helper(node->left,value);
        int right=helper(node->right,value);
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        return helper(root,0);
     }
};