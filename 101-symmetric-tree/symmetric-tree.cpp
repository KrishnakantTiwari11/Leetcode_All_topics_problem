/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* tree1, TreeNode* tree2) {
        if(!tree1 && !tree2)return true;
        if(!tree1 || !tree2)return false;
        if (tree1->val != tree2->val)
            return false;
        if(helper(tree1->left,tree2->right)==false)return false;
        if(helper(tree1->right,tree2->left)==false)return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return helper(root->left,root->right);
    }
};