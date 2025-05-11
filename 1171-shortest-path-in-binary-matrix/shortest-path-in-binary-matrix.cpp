class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n =  grid.size();
        int m=grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        q.push({{0, 0}, 1});
        visited[0][0] = 1;
        int res=INT_MAX;
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            if(row==n-1 && col==n-1){
                res=min(res,dist);
            }
            dist++;
            q.pop();
            // Up
            if (row - 1 >= 0 && grid[row - 1][col] == 0 &&
                !visited[row - 1][col]) {
                q.push({{row - 1, col}, dist});
                visited[row - 1][col] = 1;
            }

            // Down
            if (row + 1 < n && grid[row + 1][col] == 0 &&
                !visited[row + 1][col]) {
                q.push({{row + 1, col}, dist});
                visited[row + 1][col] = 1;
            }

            // Left
            if (col - 1 >= 0 && grid[row][col - 1] == 0 &&
                !visited[row][col - 1]) {
                q.push({{row, col - 1}, dist});
                visited[row][col - 1] = 1;
            }

            // Right
            if (col + 1 < m && grid[row][col + 1] == 0 &&
                !visited[row][col + 1]) {
                q.push({{row, col + 1}, dist});
                visited[row][col + 1] = 1;
            }

            // Top-left
            if (row - 1 >= 0 && col - 1 >= 0 && grid[row - 1][col - 1] == 0 &&
                !visited[row - 1][col - 1]) {
                q.push({{row - 1, col - 1}, dist});
                visited[row - 1][col - 1] = 1;
            }

            // Top-right
            if (row - 1 >= 0 && col + 1 < m && grid[row - 1][col + 1] == 0 &&
                !visited[row - 1][col + 1]) {
                q.push({{row - 1, col + 1}, dist});
                visited[row - 1][col + 1] = 1;
            }

            // Bottom-left
            if (row + 1 < n && col - 1 >= 0 && grid[row + 1][col - 1] == 0 &&
                !visited[row + 1][col - 1]) {
                q.push({{row + 1, col - 1}, dist});
                visited[row + 1][col - 1] = 1;
            }

            // Bottom-right
            if (row + 1 < n && col + 1 < m && grid[row + 1][col + 1] == 0 &&
                !visited[row + 1][col + 1]) {
                q.push({{row + 1, col + 1}, dist});
                visited[row + 1][col + 1] = 1;
            }
        }
        if(res==INT_MAX)return -1;
        return res;
    }
};