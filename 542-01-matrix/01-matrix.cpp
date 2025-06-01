class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0){
                    q.push({0, {i, j}});
                    visited[i][j] = 1;
                }
            }
        }
        while (!q.empty()) {
            int dist = q.front().first, row = q.front().second.first,
                col = q.front().second.second;
            q.pop();
            // up
            if (row - 1 >= 0 && !visited[row - 1][col] &&
                mat[row - 1][col] == 1) {
                q.push({dist + 1, {row - 1, col}});
                visited[row - 1][col] = 1;
                mat[row - 1][col] = dist + 1;
            }
            if (row + 1 < rows && !visited[row + 1][col] &&
                mat[row + 1][col] == 1) {
                q.push({dist + 1, {row + 1, col}});
                visited[row + 1][col] = 1;
                mat[row + 1][col] = dist + 1;
            }
            if (col - 1 >= 0 && !visited[row][col - 1] &&
                mat[row][col - 1] == 1) {
                q.push({dist + 1, {row, col - 1}});
                visited[row][col - 1] = 1;
                mat[row][col - 1] = dist + 1;
            }
            if (col + 1 < cols && !visited[row][col + 1] &&
                mat[row][col + 1] == 1) {
                q.push({dist + 1, {row, col + 1}});
                visited[row][col + 1] = 1;
                mat[row][col + 1] = dist + 1;
            }
        }
        return mat;
    }
};