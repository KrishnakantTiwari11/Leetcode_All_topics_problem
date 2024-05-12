#include <vector>

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = 0; i < n - 2; ++i) {
            vector<int> row;
            for (int j = 0; j < m - 2; ++j) {
                int maxVal = grid[i][j];
                for (int p = i; p < i + 3; ++p) {
                    for (int q = j; q < j + 3; ++q) {
                        maxVal = max(maxVal, grid[p][q]);
                    }
                }
                row.push_back(maxVal);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
