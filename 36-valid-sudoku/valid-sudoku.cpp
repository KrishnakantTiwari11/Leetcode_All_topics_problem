class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            unordered_set<char> row_set;
            unordered_set<char> col_set;
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.'){
                    if (row_set.find(board[row][col]) != row_set.end())
                    return false;
                row_set.insert(board[row][col]);
                }
                if (board[col][row] != '.'){
                    
                if (col_set.find(board[col][row]) != col_set.end())
                    return false;
                col_set.insert(board[col][row]);
                }
            }
        }
        for (int i = 0; i <3; i++) {
            for (int j = 0; j <3; j++) {
                unordered_set<char> matrix;
                for (int k = 0; k < 9; k++) {
                    if (board[i * 3 + k / 3][j * 3 + k % 3] == '.')
                        continue;
                    if (matrix.find(board[i * 3 + k / 3][j * 3 + k % 3]) !=
                        matrix.end())
                        return false;
                    matrix.insert(board[i * 3 + k / 3][j * 3 + k % 3]);
                }
            }
        }
        return true;
    }
};