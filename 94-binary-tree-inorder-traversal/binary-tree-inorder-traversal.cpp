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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        stack<pair<TreeNode*,int>>st;
        vector<int>preorder;
        vector<int>inorder;
        vector<int>postorder;
        st.push({root,1});
        while(!st.empty())
        {
            TreeNode*node=st.top().first;
            int num=st.top().second;
            st.pop();
            if(num==1){
                preorder.push_back(node->val);
                num++;
                st.push({node,num});
                if(node->left)st.push({node->left,1});
            }
            else if(num==2){
                inorder.push_back(node->val);
                num++;
                st.push({node,num});
                if(node->right)st.push({node->right,1});
            }
            else{
                postorder.push_back(node->val);
            }
        }
        return inorder;

    }
};