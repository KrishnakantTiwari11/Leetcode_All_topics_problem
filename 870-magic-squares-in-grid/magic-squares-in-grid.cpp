class Solution {
public:
    bool checkDiag(int k, int l, vector<vector<int>>& grid) {
        int leftDiag = grid[k][l] + grid[k + 1][l + 1] + grid[k + 2][l + 2];
        int rightDiag = grid[k][l + 2] + grid[k + 1][l + 1] + grid[k + 2][l];
        return leftDiag == rightDiag;
    }
    bool helper(int k, int l, vector<vector<int>>& grid) {
        unordered_set<int> st;
        unordered_set<int> dup;
        for (int i = k; i < k + 3; i++) {
            int temp = 0;
            for (int j = l; j < l + 3; j++) {
                if (grid[i][j] > 9 || grid[i][j] == 0)
                    return false;
                temp += grid[i][j];
                dup.insert(grid[i][j]);
            }
            st.insert(temp);
            if (st.size() == 2)
                return false;
        }
        return dup.size() == 9;
    }
    bool helper1(int k, int l, vector<vector<int>>& grid) {
        unordered_set<int> st;
        unordered_set<int> dup;
        for (int i = l; i < l + 3; i++) {
            int temp = 0;
            for (int j = k; j < k + 3; j++) {
                if (grid[j][i] > 9 || grid[j][i] == 0)
                    return false;
                temp += grid[j][i];
                dup.insert(grid[j][i]);
            }
            st.insert(temp);
            if (st.size() == 2)
                return false;
        }
        return dup.size() == 9;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int maxRow = grid[0].size() - 3;
        int maxCol = grid.size() - 3;
        int res = 0;
        for (int i = 0; i <= maxCol; i++) {
            for (int j = 0; j <= maxRow; j++) {
                if (helper(i, j, grid) && helper1(i, j, grid) &&
                    checkDiag(i, j, grid))
                    res++;
            }
        }
        return res;
    }
};
