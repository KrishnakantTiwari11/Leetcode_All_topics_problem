
class FindElements {
public:
    unordered_set<int> elements;

    void recover(TreeNode* node, int val) {
        if (!node) return;
        node->val = val;
        elements.insert(val);
        recover(node->left, val * 2 + 1);
        recover(node->right, val * 2 + 2);
    }

    FindElements(TreeNode* root) {
        recover(root, 0);
    }

    bool find(int target) {
        return elements.find(target) != elements.end();
    }
};
