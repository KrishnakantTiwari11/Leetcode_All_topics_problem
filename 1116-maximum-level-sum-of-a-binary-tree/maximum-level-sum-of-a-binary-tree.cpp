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
    int maxLevelSum(TreeNode* root) {
        int level=1;
        queue<TreeNode*>q;
        q.push(root);
        int maxSum = INT_MIN;
        int maxLevel=1;
        while(!q.empty()){
            int n=q.size();
            int tempSum=0;
            for(int i=0;i<n;i++){
                TreeNode*top = q.front();
                q.pop();
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
                tempSum+=top->val;
            }
            if(tempSum>maxSum){
                maxSum=tempSum;
                maxLevel=level;
            }
            level++;
        }
        return maxLevel;
    }
};