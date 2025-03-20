class Solution {
public:
    void helper(TreeNode* root, int target, vector<vector<int>>& res, int sum, vector<int>& temp) {
        if (!root) return;
        temp.push_back(root->val);
        sum += root->val;
        if (!root->left && !root->right && sum == target) {
            res.push_back(temp);
        }
        helper(root->left, target, res, sum, temp);
        helper(root->right, target, res, sum, temp);
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(root, targetSum, res, 0, temp);
        return res;
    }
};
