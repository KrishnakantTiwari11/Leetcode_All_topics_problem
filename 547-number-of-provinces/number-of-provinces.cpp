class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int curr) {
        visited[curr] = 1;
        for (auto neigh : isConnected[curr]) {
            if (!visited[neigh]) {
                dfs(isConnected, visited, neigh);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
        int V = isConnected.size();
        vector<vector<int>> edges(V + 1);
        vector<int> visited(V+1, 0);
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j]) {
                    edges[i + 1].push_back(j + 1);
                    edges[j + 1].push_back(i + 1);
                }
            }
        }
        for (int i = 1; i <=V; i++) {
            if (!visited[i]) {
                res++;
                dfs(edges, visited, i);
            }
        }
        return res;
    }
};