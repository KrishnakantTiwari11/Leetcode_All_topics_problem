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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                pair<TreeNode*,pair<int,int>>front_val=q.front();
                q.pop();
                TreeNode*node=front_val.first;
                int row=front_val.second.first;
                int col=front_val.second.second;
                mp[col][row].push_back(node->val);
                if(node->right)q.push({node->right,{row+1,col+1}});
                if(node->left)q.push({node->left,{row+1,col-1}});
            }
        }
        vector<vector<int>>res;
        for(auto arr:mp){
            vector<int>temp;
            for(auto ch:arr.second){
                vector<int>temp2=ch.second;
                sort(temp2.begin(),temp2.end());
                temp.insert(temp.end(),temp2.begin(),temp2.end());
            }
            res.push_back(temp);
        }
        return res;
    }
};