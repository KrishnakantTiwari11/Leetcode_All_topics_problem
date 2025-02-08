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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        int smallest=root->val;
        long long sec_smallest = LLONG_MAX;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            int value=curr->val;
            if (value < smallest) {
                    sec_smallest = smallest;
                    smallest = value;
                }
            else if (value > smallest && value < sec_smallest) 
                sec_smallest = value;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return (sec_smallest == LLONG_MAX) ? -1 : sec_smallest;
    }
};