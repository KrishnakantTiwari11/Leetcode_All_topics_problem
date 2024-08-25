class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        if(root)stk.push(root);
        vector<int> ans;
        while(stk.size())
        {
            auto p = stk.top();
            
            if(p == nullptr)
            {
                stk.pop();
                ans.push_back(stk.top()->val);
                stk.pop();
                continue;
            }
            
            stk.push(nullptr);
    
            if(p->right)stk.push(p->right);
            if(p->left)stk.push(p->left);
        }
        return ans;
    }
};