/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "";
        }
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node == nullptr) {
                    ans.append("#,");
                    continue;
                }
                ans.append(to_string(node->val) + ",");
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0)return NULL;
        queue<TreeNode*>q;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode*root=new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*node=q.front();
                q.pop();
                getline(s,str,',');
                if(str=="#"){
                   node->left=NULL;
                }
                else{
                    TreeNode*temp1=new TreeNode(stoi(str));
                    node->left=temp1;
                    q.push(temp1);
                }
                getline(s,str,',');
                if(str=="#"){
                   node->right=NULL;
                }
                else{
                    TreeNode*temp2=new TreeNode(stoi(str));
                    node->right=temp2;
                    q.push(temp2);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));