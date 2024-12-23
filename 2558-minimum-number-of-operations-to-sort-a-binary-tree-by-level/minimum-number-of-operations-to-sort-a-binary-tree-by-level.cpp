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
int minswap(vector<TreeNode*> temp) {
    int n = temp.size();
    vector<pair<int, int>> pair(n);
    for (int i = 0; i < n; i++) {
        pair[i] = {temp[i]->val, i};
    }

    sort(pair.begin(), pair.end());

    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || pair[i].second == i) {
            continue;
        }

        int cycle_size = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            j = pair[j].second;
            cycle_size++;
        }

        if (cycle_size > 1) {
            swaps += cycle_size - 1;
        }
    }

    return swaps;
}
    

    int minimumOperations(TreeNode* root) {
        vector<vector<TreeNode*>>levels;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<TreeNode*>level;
            for(int i=0;i<size;i++)
            {
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                    level.push_back(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                    level.push_back(temp->right);
                }
            }
            levels.push_back(level);
        }

        int res=0;
        int rows_level=levels.size();
        for(int i=0;i<rows_level;i++)
        {
            res+=minswap(levels[i]);
        }
        return res;
    }
};