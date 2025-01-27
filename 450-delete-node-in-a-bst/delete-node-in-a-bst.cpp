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
    TreeNode* find_node(TreeNode*root,int key){
        TreeNode*curr=root;
        TreeNode*prev=NULL;
        while(curr){
            if(curr->val==key)return prev;
            if(key>curr->val){
                prev=curr;
                curr=curr->right;
            }
            else{
                prev=curr;
                curr=curr->left;
            }
        }
        return NULL;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        if(!root->left && !root->right && root->val==key)return NULL;
        if(root->val==key){
            if(!root->left){
                return root->right;
            }
            else if(!root->right){
                return root->left;
            }
            TreeNode*temp=root->left;
            TreeNode*curr=temp;
            while(temp->right){
                temp=temp->right;
            }
            temp->right=root->right;
            return curr;
        }
        TreeNode*parent=find_node(root,key);
        if(!parent)return root;
        TreeNode*del=nullptr;
        if(parent->left && parent->left->val==key){
            del=parent->left;
            if(!del->left && !del->right){
                parent->left=NULL;
                return root;
            }
            if(!del->right){
                parent->left=del->left;
                return root;
            }
            else if(!del->left){
                parent->left=del->right;
                return root;
            }
            TreeNode*del_r=del->right;
            TreeNode*del_l=del->left;
            parent->left=del_r;
            while(del_r->left){
                del_r=del_r->left;
            }
            del_r->left=del_l;
            return root;
        }
        else{
            del=parent->right;
             if(!del->left && !del->right){
                parent->right=NULL;
                return root;
            }
            if(!del->right){
                parent->right=del->left;
                return root;
            }
            else if(!del->left){
                parent->right=del->right;
                return root;
            }
            TreeNode*del_r=del->right;
            TreeNode*del_l=del->left;
            parent->right=del_r;
            while(del_r->left){
                del_r=del_r->left;
            }
            del_r->left=del_l;
            return root;
        }

        return root;
    }
};