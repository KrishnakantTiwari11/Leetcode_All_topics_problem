class Solution {
public:
    void solve(vector<vector<string>>& res, vector<string>& temp, int col, int n,vector<int> & left_row,vector<int> & low_diag,vector<int>& up_diag) {
        if (col >= n) {
            res.push_back(temp);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (left_row[row] == 0 && low_diag[row + col] == 0 &&
                up_diag[n - 1 + col - row] == 0) {
                temp[row][col] = 'Q';
                left_row[row] = 1;
                low_diag[row + col] = 1;
                up_diag[n - 1 + col - row] = 1;
                solve(res, temp, col+1, n,left_row,low_diag,up_diag);
                left_row[row] = 0;
                low_diag[row + col] = 0;
                up_diag[n - 1 + col - row] = 0;
                temp[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>temp(n,string(n,'.'));
        vector<vector<string>>res;
        vector<int>left_row(n);
        vector<int>low_diag(2*n-1);
        vector<int>up_diag(2*n-1);
        solve(res,temp,0,n,left_row,low_diag,up_diag);
        return res;
    }
};