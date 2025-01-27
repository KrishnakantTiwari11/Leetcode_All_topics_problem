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
    bool inorder(TreeNode*node,vector<int>&arr){
        if(!node)return true;
        if(!inorder(node->left,arr))return false;
        if(!arr.empty()){
            if(node->val<=arr.back())return false;
        }
        arr.push_back(node->val);
        if(!inorder(node->right,arr))return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        vector<int>res;
        return inorder(root,res);
    }
};