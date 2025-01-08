class Solution {
public:
    void solve(vector<vector<string>>& res, vector<string>& temp, int col, int n,vector<int> & left_row,vector<int> & up_left,vector<int>& down_right) {
        if (col >= n) {
            res.push_back(temp);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (left_row[row] == 0 && up_left[row + col] == 0 &&
                down_right[n - 1 + col - row] == 0) {
                temp[row][col] = 'Q';
                left_row[row] = 1;
                up_left[row + col] = 1;
                down_right[n - 1 + col - row] = 1;
                solve(res, temp, col+1, n,left_row,up_left,down_right);
                left_row[row] = 0;
                up_left[row + col] = 0;
                down_right[n - 1 + col - row] = 0;
                temp[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>temp(n,string(n,'.'));
        vector<vector<string>>res;
        vector<int>left_row(n);
        vector<int>up_left(2*n-1);
        vector<int>down_right(2*n-1);
        solve(res,temp,0,n,left_row,up_left,down_right);
        return res;
    }
};