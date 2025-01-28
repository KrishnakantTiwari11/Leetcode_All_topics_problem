class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);
        for (int i = 1; i < n; i++) {
            TreeNode* temp = nullptr;
            TreeNode* curr = new TreeNode(preorder[i]);
            while (!st.empty() && preorder[i] > st.top()->val) {
                temp = st.top();
                st.pop();
            }
            if (temp) {
                temp->right = curr;
            }
            else {
                temp = st.top();
                temp->left = curr;
            }
            st.push(curr);
        }

        return root;
    }
};
