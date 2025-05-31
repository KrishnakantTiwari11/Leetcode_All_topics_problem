class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int fresh = 0, res = 0;
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({0, {i, j}});
                    visited[i][j] = 1;
                }
            }
        }
        while (!q.empty()) {
            int time = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            res = max(res, time);
            // down
            if (row + 1 < rows && !visited[row + 1][col] &&
                grid[row + 1][col] == 1) {
                q.push({time+1, {row + 1, col}});
                fresh--;
                visited[row + 1][col] = 1;
            }
            // right
            if (col + 1 < cols && !visited[row][col + 1] &&
                grid[row][col + 1] == 1) {
                q.push({time+1, {row, col + 1}});
                fresh--;
                visited[row][col + 1] = 1;
            }
            // up
            if (row - 1 >= 0 && !visited[row - 1][col] &&
                grid[row - 1][col] == 1) {
                q.push({time+1, {row - 1, col}});
                fresh--;
                visited[row - 1][col] = 1;
            }

            // left
            if (col - 1 >= 0 && !visited[row][col - 1] &&
                grid[row][col - 1] == 1) {
                q.push({time+1, {row, col - 1}});
                fresh--;
                visited[row][col - 1] = 1;
            }
        }
        if (fresh == 0)
            return res;
        return -1;
    }
};