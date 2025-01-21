class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "null";
        queue<TreeNode*> q;
        string enc = "";
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node == nullptr) {
                enc.append("null,");
            } else {
                enc.append(to_string(node->val) + ",");
                q.push(node->left);
                q.push(node->right);
            }
        }
        if (!enc.empty()) enc.pop_back();
        return enc;
    }

    TreeNode* deserialize(string data) {
        if (data == "null") return nullptr;

        vector<string> nodes;
        stringstream ss(data);
        string node;
        while (getline(ss, node, ',')) {
            nodes.push_back(node);
        }

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < nodes.size()) {
            TreeNode* parent = q.front();
            q.pop();

            if (nodes[i] != "null") {
                parent->left = new TreeNode(stoi(nodes[i]));
                q.push(parent->left);
            }
            i++;

            if (i < nodes.size() && nodes[i] != "null") {
                parent->right = new TreeNode(stoi(nodes[i]));
                q.push(parent->right);
            }
            i++;
        }

        return root;
    }
};
