class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colored(n, -1);
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            if (colored[i] == -1) {
                q.push({i, 0});
                colored[i] = 0;
                while (!q.empty()) {
                    int curr = q.front().first;
                    int color = q.front().second;
                    q.pop();
                    for (auto ch : graph[curr]) {
                        //if not visited
                        if (colored[ch] == -1) {
                            if (color == 0) {
                                q.push({ch, 1});
                                colored[ch] = 1;
                            } else { 
                                q.push({ch, 0});
                                colored[ch] = 0;
                            } // if visited
                        } else if (colored[ch] == color) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};