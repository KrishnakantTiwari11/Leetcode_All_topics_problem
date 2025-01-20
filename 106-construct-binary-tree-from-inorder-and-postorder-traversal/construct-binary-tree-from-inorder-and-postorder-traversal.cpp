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
    TreeNode* helper(vector<int>& postorder, int post_start, int post_end,
                     vector<int>& inorder, int in_start, int in_end,
                     unordered_map<int, int>& mp) {
        if (post_start < post_end || in_start > in_end)
            return NULL;
        TreeNode* root = new TreeNode(postorder[post_start]);
        int in_root = mp[root->val];
        int num_right = in_end - in_root;
        TreeNode* right_side =
            helper(postorder, post_start - 1, post_start - num_right, inorder,
                   in_root + 1, in_end, mp);
        TreeNode* left_side =
            helper(postorder, post_start - num_right - 1, post_end, inorder,
                   in_start, in_root - 1, mp);
        root->right = right_side;
        root->left = left_side;
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return helper(postorder, n - 1, 0, inorder, 0, n - 1, mp);
    }
};