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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        stack<TreeNode*>st;
        TreeNode*root=new TreeNode(preorder[0]);
        st.push(root);
        for(int i=1;i<n;i++){
            int curr=preorder[i];
            TreeNode*temp=NULL;
            while(!st.empty() && st.top()->val<curr){
                 temp=st.top();
                 st.pop();
            }
            if(temp){
                temp->right=new TreeNode(preorder[i]);
                st.push(temp->right);
            }
            else{
                temp=st.top();
                temp->left=new TreeNode(preorder[i]);
                st.push(temp->left);
            }
        }
        return root;
    }
};