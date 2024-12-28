class Solution {
public:
    bool res = false;
    int currsum = 0;

    void helper(TreeNode* node, int target) {
        currsum += node->val;
        if (!node->left && !node->right) {
            if (currsum == target) {
                res = true;
            }
        }
        if (node->left) {
            helper(node->left, target);
        }
        if (node->right) {
            helper(node->right, target);
        }
        currsum -= node->val;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        helper(root, targetSum);
        return res;
    }
};
