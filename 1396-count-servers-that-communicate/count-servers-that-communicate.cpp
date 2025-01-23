class Solution {
public:
    bool find_row(int row,vector<vector<int>>& grid,int n,int col){
         for(int i=0;i<n;i++){
            if(i==col)continue;
            if(grid[row][i]==1)return true;
         }
         return false;
    }
    bool find_col(int col,vector<vector<int>>& grid,int n,int row){
         for(int i=0;i<n;i++){
            if(i==row)continue;
            if(grid[i][col]==1)return true;
         }
         return false;
    }
    int countServers(vector<vector<int>>& grid) {
        int row_size=grid.size();
        int col_size=grid[0].size();
        int count=0;
        for(int row=0;row<row_size;row++){
            for(int col=0;col<col_size;col++){
                if(grid[row][col]==1){
                    if(find_row(row,grid,col_size,col)){
                        count++;
                    }
                    else{
                        if(find_col(col,grid,row_size,row)){
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};