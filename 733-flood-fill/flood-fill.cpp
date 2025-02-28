class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int originalColor =image[sr][sc]; 
        q.push({sr, sc});
        visited[sr][sc] = 1;

        while (!q.empty()) {
            int temp_sr = q.front().first;
            int temp_sc = q.front().second;
            q.pop();

            if (temp_sc - 1 >= 0 &&
                image[temp_sr][temp_sc - 1] == originalColor &&
                !visited[temp_sr][temp_sc - 1]) {
                q.push({temp_sr, temp_sc - 1});
                visited[temp_sr][temp_sc - 1] = 1;
            }
            if (temp_sc + 1 < m &&
                image[temp_sr][temp_sc + 1] == originalColor &&
                !visited[temp_sr][temp_sc + 1]) {
                q.push({temp_sr, temp_sc + 1});
                visited[temp_sr][temp_sc + 1] = 1;
            }
            if (temp_sr - 1 >= 0 &&
                image[temp_sr - 1][temp_sc] == originalColor &&
                !visited[temp_sr - 1][temp_sc]) {
                q.push({temp_sr - 1, temp_sc});
                visited[temp_sr - 1][temp_sc] = 1;
            }
            if (temp_sr + 1 < n &&
                image[temp_sr + 1][temp_sc] == originalColor &&
                !visited[temp_sr + 1][temp_sc]) {
                q.push({temp_sr + 1, temp_sc});
                visited[temp_sr + 1][temp_sc] = 1;
            }

            image[temp_sr][temp_sc] = color; // Update the color
        }

        return image;
    }
};
