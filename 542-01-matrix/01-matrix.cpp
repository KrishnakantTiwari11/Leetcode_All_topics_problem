class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> res(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        while (!q.empty()) {
            int dist = q.front().second;
            int row = q.front().first.first;
            int col = q.front().first.second;
            q.pop();
            res[row][col] = dist;

            // up
            if (row - 1 >= 0 && mat[row - 1][col] == 1 &&
                !visited[row - 1][col]) {
                q.push({{row - 1, col}, dist+1});
                visited[row - 1][col] = 1;
            }
            // Right
            if (col + 1 < n && mat[row][col + 1] == 1 &&
                !visited[row][col + 1]) {
                q.push({{row, col + 1}, dist + 1});
                visited[row][col + 1] = 1;
            }

            // Left
            if (col - 1 >= 0 && mat[row][col - 1] == 1 &&
                !visited[row][col - 1]) {
                q.push({{row, col - 1}, dist + 1});
                visited[row][col - 1] = 1;
            }

            // Down
            if (row + 1 < m && mat[row + 1][col] == 1 &&
                !visited[row + 1][col]) {
                q.push({{row + 1, col}, dist + 1});
                visited[row + 1][col] = 1;
            }
        }
        return res;
    }
};