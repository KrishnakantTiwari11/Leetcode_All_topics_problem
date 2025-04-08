class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        int res = 0;
        int oranges = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
                if (grid[i][j] == 1)
                    oranges++;
            }
        }
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int min = q.front().second;
            q.pop();
            res = max(res, min);
            // Right
            if (col + 1 < n && grid[row][col + 1] == 1 &&
                !visited[row][col + 1]) {
                q.push({{row, col + 1}, min + 1});
                visited[row][col + 1] = 1;
                oranges--;
            }

            // Left
            if (col - 1 >= 0 && grid[row][col - 1] == 1 &&
                !visited[row][col - 1]) {
                q.push({{row, col - 1}, min + 1});
                visited[row][col - 1] = 1;
                oranges--;
            }

            // Down
            if (row + 1 < m && grid[row + 1][col] == 1 &&
                !visited[row + 1][col]) {
                q.push({{row + 1, col}, min + 1});
                visited[row + 1][col] = 1;
                oranges--;
            }

            // Up
            if (row - 1 >= 0 && grid[row - 1][col] == 1 &&
                !visited[row - 1][col]) {
                q.push({{row - 1, col}, min + 1});
                visited[row - 1][col] = 1;
                oranges--;
            }
        }
        return oranges == 0 ? res : -1;
    }
};