class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        //left & right
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                visited[i][0]=1;
            }
            if (board[i][n-1] == 'O') {
                q.push({i, n-1});
                visited[i][n-1]=1;
            }
        }
        //up & down
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                q.push({0, i});
                visited[0][i]=1;
            }
            if (board[m - 1][i] == 'O') {
                q.push({m - 1, i});
                visited[m-1][i]=1;
            }
        }
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // Up
            if (row - 1 >= 0 && !visited[row - 1][col] &&
                board[row - 1][col] == 'O') {
                q.push({row - 1, col});
                visited[row - 1][col] = 1;
            }

            // Down
            if (row + 1 < m && !visited[row + 1][col] &&
                board[row + 1][col] == 'O') {
                q.push({row + 1, col});
                visited[row + 1][col] = 1;
            }

            // Left
            if (col - 1 >= 0 && !visited[row][col - 1] &&
                board[row][col - 1] == 'O') {
                q.push({row, col - 1});
                visited[row][col - 1] = 1;
            }

            // Right
            if (col + 1 < n && !visited[row][col + 1] &&
                board[row][col + 1] == 'O') {
                q.push({row, col + 1});
                visited[row][col + 1] = 1;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};