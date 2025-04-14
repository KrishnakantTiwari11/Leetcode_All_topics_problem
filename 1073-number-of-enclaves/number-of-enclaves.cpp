class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int one_count = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    one_count++;
                }
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) &&
                    grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            one_count--;
            // up
            if (row - 1 >= 0 && !visited[row - 1][col] && grid[row-1][col]==1) {
                q.push({row - 1, col});
                visited[row - 1][col] = 1;
            } // Left
            if (col - 1 >= 0 && !visited[row][col - 1] && grid[row][col-1]==1) {
                q.push({row, col - 1});
                visited[row][col - 1] = 1;
            }

            // Right
            if (col + 1 < n && !visited[row][col + 1] && grid[row][col+1]==1) {
                q.push({row, col + 1});
                visited[row][col + 1] = 1;
            }

            // Down
            if (row + 1 < m && !visited[row + 1][col] && grid[row+1][col]==1) {
                q.push({row + 1, col});
                visited[row + 1][col] = 1;
            }
        }
        return one_count;
    }
};