class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m, n;
        vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> result(m, (vector<int>(n, -1)));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> que;
            que = q.front();
            q.pop();
            int i = que.first;
            int j = que.second;
            for (auto it : dir) {
                int newi = i + it[0];
                int newj = j + it[1];
                if (newi >= 0 && newj >= 0 && newi < m && newj < n &&
                    result[newi][newj] == -1) {
                    result[newi][newj] = result[i][j] + 1;
                    q.push({newi, newj});
                }
            }
        }
        return result;
    }
};