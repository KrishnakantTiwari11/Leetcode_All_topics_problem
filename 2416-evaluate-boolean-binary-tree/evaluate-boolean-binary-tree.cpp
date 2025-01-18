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
    int helper(TreeNode*node){
        if(!node->left && !node->right)return node->val;
        int left=helper(node->left);
        int right=helper(node->right);
        if(node->val==2){
            return (left || right);
        }
        if(node->val==3){
            return (left && right);
        }
        return -1;
    }
    bool evaluateTree(TreeNode* root) {
        return helper(root);
    }
};