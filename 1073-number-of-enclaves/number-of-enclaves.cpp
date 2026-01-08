class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int rows = grid.size(),cols=grid[0].size();
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        int oneCount=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    oneCount++;
                }
                if((i==0 || i==rows-1 || j==0 || j==cols-1) && grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=1;
                    oneCount--;
                }
            }
        }
        while(!q.empty()){
            pair<int,int>top = q.front();
            q.pop();
            int row=top.first,col=top.second;
            if(row>0 && grid[row-1][col]==1 && !visited[row-1][col]){
                visited[row-1][col]=1;
                q.push({row-1,col});
                oneCount--;
            }
            if(row<rows-1 && grid[row+1][col]==1 && !visited[row+1][col]){
                visited[row+1][col]=1;
                q.push({row+1,col});
                oneCount--;
            }
            if(col>0 && grid[row][col-1]==1 && !visited[row][col-1]){
                visited[row][col-1]=1;
                q.push({row,col-1});
                oneCount--;
            }
            if(col<cols-1 && grid[row][col+1]==1 && !visited[row][col+1]){
                visited[row][col+1]=1;
                q.push({row,col+1});
                oneCount--;
            }
        }
        return oneCount;
    }
};