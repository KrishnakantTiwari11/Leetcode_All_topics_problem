class Solution {
private:
    int currTime = 1;

public:
    void helper(vector<vector<int>>& adj, vector<int>& visited, vector<int>& tin,
                vector<int>& low, vector<vector<int>>& res, int node,
                int parent) {
        tin[node] = low[node] = currTime;
        visited[node]=1;
        currTime++;
        for (auto neigh : adj[node]) {
            if (neigh == parent)
                continue;
            if (!visited[neigh]) {
                helper(adj, visited, tin, low, res, neigh, node);
                low[node] = min(low[node], low[neigh]);
                if (tin[node] < low[neigh]) {
                    res.push_back({node, neigh});
                }
            } else {
                low[node] = min(low[node], low[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(n), res;
        for (auto conn : connections) {
            int u = conn[0], v = conn[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n, 0), tin(n), low(n);
        helper(adj, visited, tin, low, res, 0, -1);
        return res;
    }
};