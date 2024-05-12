class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans;
        
        for (int i = 0; i < m - 2; ++i) {
            vector<int> row;
            for (int j = 0; j < n - 2; ++j) {
                int smax = grid[i][j];
                for (int p = i; p < i + 3; ++p) {
                    for (int q = j; q < j + 3; ++q) {
                        smax = max(smax, grid[p][q]);
                    }
                }
                row.push_back(smax);
            }
            ans.push_back(row);
        }
        
        return ans;
    }
};
