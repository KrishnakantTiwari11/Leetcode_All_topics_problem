class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
    }
    int next() {
        int val = nodes.front();
        nodes.pop();
        return val;
    }
    bool hasNext() {
        return !nodes.empty();
    }
private:
    queue<int> nodes;
    
    void inorderTraversal(TreeNode* node) {
        if (!node) return;
        inorderTraversal(node->left);
        nodes.push(node->val);
        inorderTraversal(node->right);
    }
};