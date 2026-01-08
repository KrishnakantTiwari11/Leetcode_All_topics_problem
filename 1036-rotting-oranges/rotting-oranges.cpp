class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> q;
        int fresh = 0, maxTime = 0;
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
            }
        }
        while (!q.empty()) {
            tuple<int,int,int>top = q.front();
            q.pop();
            int row = get<0>(top), col = get<1>(top), time = get<2>(top);
            maxTime = max(maxTime,time);
            if(row>0 && grid[row-1][col]==1){
                q.push({row-1,col,time+1});
                grid[row-1][col]=2;
                fresh--;
            }
            if(row<rows-1 && grid[row+1][col]==1){
                q.push({row+1,col,time+1});
                grid[row+1][col]=2;
                fresh--;
            }
            if(col>0 && grid[row][col-1]==1){
                q.push({row,col-1,time+1});
                grid[row][col-1]=2;
                fresh--;
            }
            if(col<cols-1 && grid[row][col+1]==1){
                q.push({row,col+1,time+1});
                grid[row][col+1]=2;
                fresh--;
            }
        }
        if(fresh<=0){
            return maxTime;
        }
        return -1;
    }
};