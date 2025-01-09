class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int i,
               vector<pair<int, int>>& temp) {
        if (i >= word.size()) {
            return true;
        }
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] == word[i] &&
                    isNeigh(row, col,temp)) {
                    board[row][col] = '.';
                    temp.push_back({row, col});
                    if (solve(board, word, i + 1, temp))
                        return true;
                    temp.pop_back();
                    board[row][col] = word[i];
                }
            }
        }
        return false;
    }

    bool isNeigh(int row, int col,vector<pair<int, int>>& temp) {
        if (temp.size()==0)
            return true;
        int prev_row = temp.back().first;
        int prev_col = temp.back().second;
        if (prev_row == row) {
            if (abs(col - prev_col) <= 1)
                return true;
        }
        if (prev_col == col) {
            if (abs(row - prev_row) <= 1)
                return true;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> temp;
        return solve(board, word, 0, temp);
    }
};