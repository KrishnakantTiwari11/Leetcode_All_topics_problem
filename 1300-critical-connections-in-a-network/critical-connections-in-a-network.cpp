class Solution {
private:
    int currTime = 1;

public:
    void helper(vector<vector<int>>& adj, vector<vector<int>>& res,
                vector<int>& tin, vector<int>& low, vector<int>& visited,
                int node, int parent) {
        visited[node] = 1;
        tin[node] = low[node] = currTime;
        currTime++;
        for (auto neigh : adj[node]) {
            if (neigh == parent)
                continue;
            if (!visited[neigh]) {
                helper(adj, res, tin, low, visited, neigh, node);
                low[node] = min(low[node], low[neigh]);
                if(tin[node]<low[neigh]){
                    res.push_back({neigh,node});
                }
            } else {
                low[node] = min(low[node], low[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(n), res;
        for (auto edge : connections) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> tin(n), low(n), visited(n);
        helper(adj, res, tin, low, visited, 0, -1);
        return res;
    }
};