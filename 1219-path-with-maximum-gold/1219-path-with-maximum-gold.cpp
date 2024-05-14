#include <vector>
using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, dfs(grid, i, j));
                }
            }
        }
        return maxGold;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        
        int temp = grid[i][j];
        grid[i][j] = 0;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int maxGold = 0;
        for (auto& dir : directions) {
            maxGold = max(maxGold, dfs(grid, i + dir[0], j + dir[1]));
        }
        grid[i][j] = temp;
        return maxGold + temp;
    }
};
