class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int res = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    fresh++;
                else if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
             res = max(res, time);
            q.pop();
            time++;
            // up
            if (i - 1 >= 0 && grid[i - 1][j] == 1 && !visited[i - 1][j]) {
                q.push({{i - 1, j}, time});
                visited[i - 1][j] = 1;
                fresh--;
            }
            // down
            if (i + 1 < m && grid[i + 1][j] == 1 && !visited[i + 1][j]) {
                q.push({{i + 1, j}, time});
                visited[i + 1][j] = 1;
                fresh--;
            }

            // left
            if (j - 1 >= 0 && grid[i][j - 1] == 1 && !visited[i][j - 1]) {
                q.push({{i, j - 1}, time});
                visited[i][j - 1] = 1;
                fresh--;
            }

            // right
            if (j + 1 < n && grid[i][j + 1] == 1 && !visited[i][j + 1]) {
                q.push({{i, j + 1}, time});
                visited[i][j + 1] = 1;
                fresh--;
            }
        }
        if(fresh==0)return res;
        return -1;
    }
};