class Solution {
public:
    bool helper(vector<vector<int>>& graph, vector<int>& colored, int curr, int parent) {
        if (parent == -1) {
            colored[curr] = 0;
        } else if (colored[curr] == -1) {
            colored[curr] = 1 - colored[parent];
        } else {
            if (colored[curr] == colored[parent]) return false;
            return true;
        }

        for (int ch : graph[curr]) {
            if (!helper(graph, colored, ch, curr))
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colored(n, -1);

        for (int i = 0; i < n; i++) {
            if (colored[i] == -1) {
                if (!helper(graph, colored, i, -1))
                    return false;
            }
        }
        return true;
    }
};
