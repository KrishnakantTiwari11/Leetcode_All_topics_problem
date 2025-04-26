class Solution {
public:
    bool helper(vector<vector<int>>& mat, vector<int>& visited,
                vector<int>& path, vector<int>& res, int curr) {
        visited[curr] = 1;
        path[curr] = 1;
        for (auto neigh : mat[curr]) {
            if (!visited[neigh]) {
                if (helper(mat, visited, path, res, neigh))
                    return true;
            } else if (path[neigh]) {
                return true;
            }
        }
        path[curr] = 0;
        res.push_back(curr);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> visited(n, 0), path(n, 0), res;
        vector<vector<int>> mat(n);
        for (auto edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            mat[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (helper(mat, visited, path,res, i))
                    return {};
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};