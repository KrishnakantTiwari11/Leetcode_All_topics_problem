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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*,TreeNode*>>st;
        st.push({p,q});
        while(!st.empty()){
            TreeNode*node1=st.top().first;
            TreeNode*node2=st.top().second;
            st.pop();
            if(!node1 && !node2){
                continue;
            }
            if(!node1 || !node2){
                return false;
            }
            if(node1->val!=node2->val){
                return false;
            }
            st.push({node1->right,node2->right});
            st.push({node1->left,node2->left});
        }
        return true;
    }
};