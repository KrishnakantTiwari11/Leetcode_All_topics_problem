class Solution {
public:
    bool isSafe(vector<vector<string>>&board, int row, int col,
                vector<int>& rowConfig,int n) {
        if (rowConfig[row])
            return false;
             int i = row, j = col;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == "Q") return false;
        i--; j--;
    }
    i = row; j = col;
    while (i < n && j >= 0) {
        if (board[i][j] == "Q") return false;
        i++; j--;
    }

    return true;
    }
    void solve(vector<vector<string>>& board, vector<vector<string>>& res,
               int n, int col,vector<int>&rowConfig) {
        if (col == n) {
            vector<string> resTemp;
            for (int i = 0; i < n; i++) {
                string temp = "";
                for (int j = 0; j < n; j++) {
                    temp += board[i][j];
                }
                resTemp.push_back(temp);
            }
            res.push_back(resTemp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isSafe(board, i, col, rowConfig,n)) {
                rowConfig[i] = 1;
                board[i][col] = "Q";
                solve(board, res, n, col + 1,rowConfig);
                board[i][col] = ".";
                rowConfig[i] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<int> rowConfig(n, 0);
        solve(board, res, n, 0, rowConfig);
        return res;
    }
};