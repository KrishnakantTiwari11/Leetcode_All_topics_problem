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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        vector<vector<int>> res;
        stack<int> st;
        queue<TreeNode*> q;
        q.push(root);
        bool isodd = true;
        while (!q.empty()) {
            int n = q.size();
            vector<int>temp2;
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
                if(!isodd){
                    st.push(temp->val);
                }
                else
                {
                    temp2.push_back(temp->val);
                }    
            }
            if(!isodd){
                vector<int>temp;
                while(!st.empty()){
                int val=st.top();
                st.pop();
                temp.push_back(val);
            }
            res.push_back(temp);
            }
            else
            {
                res.push_back(temp2);
            }
            isodd=!isodd;
        }
        return res;
    }
};