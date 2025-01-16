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
        if(!node){
            return 0;
        }
        int left=helper(node->left);
        if(left==-1)return -1;
        int right=helper(node->right);
        if(right==-1)return -1;
        if(abs(left-right)>1)return -1;
        return max(left,right)+1;

    }
    bool isBalanced(TreeNode* root) {
        if(helper(root)==-1)return false;
        return true;
    }
};