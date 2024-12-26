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
    string sub(TreeNode*node,unordered_map<string,vector<TreeNode*>>& mp){
        if(node==NULL){
            return "#";
        }
        string left=sub(node->left,mp);
        string right=sub(node->right,mp);
        string key=to_string(node->val)+","+left+","+right;
        mp[key].push_back(node);
        return key;
    }
 
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot){
            return false;
        }
        unordered_map<string,vector<TreeNode*>>mp;
        unordered_map<string,vector<TreeNode*>>mp1;
        sub(root,mp);
        string res=sub(subRoot,mp1);
        if(mp.find(res)!=mp.end()){
            return true;
        }
        return false;
    }
};