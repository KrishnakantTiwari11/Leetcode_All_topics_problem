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
    bool ans;
    int find(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (!ans)
            return 0;
        int maxleft = find(root->left);
        int maxright = find(root->right);
        if (abs(maxleft - maxright) > 1) {
            ans = false;
        }
        return max(maxleft, maxright) + 1;
    }
    bool isBalanced(TreeNode* root) {
        ans = true;
        int temp = find(root);
        return ans;
    }
};