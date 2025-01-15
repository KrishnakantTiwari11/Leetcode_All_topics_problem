/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findp(TreeNode* node, TreeNode* p, vector<TreeNode*>& temp) {
        if (!node)
            return false;
        temp.push_back(node);
        if (node == p)
            return true;
        if (findp(node->left, p, temp))
            return true;
        if (findp(node->right, p, temp))
            return true;
        temp.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> temp1;
        vector<TreeNode*> temp2;
        findp(root, p, temp1);
        findp(root, q, temp2);
        int i = 0;
        while (i < temp1.size() && i < temp2.size() && temp1[i] == temp2[i]) {
            i++;
        }
        return temp1[i - 1];
    }
};