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
    bool res=false;
    void helper(TreeNode*node,int target){
        if(!node->left && !node->right){
            if(node->val==target){
                res=true;
            }
        }
        if(node->left){
            node->left->val+=node->val;
            helper(node->left,target);
        }
        if(node->right){
            node->right->val+=node->val;
            helper(node->right,target);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        helper(root,targetSum);
        return res;
    }
};