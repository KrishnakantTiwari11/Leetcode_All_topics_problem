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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        vector<int>res;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int max_num=INT_MIN;
            for(int i=0;i<size;i++){
                 TreeNode*node=q.front();
                 q.pop();
                 max_num=max(max_num,node->val);
                 if(node->left)q.push(node->left);
                 if(node->right)q.push(node->right);
            }
            res.push_back(max_num);
        }
        return res;
    }
};