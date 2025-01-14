class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root; // If tree is empty, return NULL

        vector<vector<Node*>> result;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            vector<Node*> levelNodes;

            for (int i = 0; i < levelSize; i++) {
                Node* current = q.front();
                q.pop();

                levelNodes.push_back(current);

                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }

            result.push_back(levelNodes);
        }

        for (int i = 0; i < result.size(); i++) {
            int n = result[i].size();
            for (int j = 0; j < n - 1; j++) {
                result[i][j]->next = result[i][j + 1];
            }
            result[i][n - 1]->next = NULL;
        }

        return root; 
    }
};
