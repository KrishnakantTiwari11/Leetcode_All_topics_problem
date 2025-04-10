class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = 1;
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // up
            if (row - 1 >= 0 && !visited[row - 1][col] &&
                image[row - 1][col] == image[row][col]) {
                q.push({row - 1, col});
                visited[row - 1][col]=1;
            }

            // Right
            if (col + 1 < n && !visited[row][col + 1] &&
                image[row][col + 1] == image[row][col]) {
                q.push({row, col + 1});
                visited[row][col + 1]=1;
            }

            // Left
            if (col - 1 >= 0 && !visited[row][col - 1] &&
                image[row][col - 1] == image[row][col]) {
                q.push({row, col - 1});
                visited[row][col - 1]=1;
            }

            // Down
            if (row + 1 < m && !visited[row + 1][col] &&
                image[row + 1][col] == image[row][col]) {
                q.push({row + 1, col});
                visited[row + 1][col]=1;
            }
            image[row][col] = color;
        }
        return image;
    }
};