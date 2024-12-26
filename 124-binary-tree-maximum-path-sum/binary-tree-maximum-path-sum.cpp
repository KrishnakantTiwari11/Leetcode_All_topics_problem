class Solution {
public:
    int maxSum = INT_MIN; 

    int maxPath(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int left = max(0, maxPath(node->left));  
        int right = max(0, maxPath(node->right)); 
        maxSum = max(maxSum, left + right + node->val);
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return maxSum; 
    }
};
