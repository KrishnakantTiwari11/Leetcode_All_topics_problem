class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minrow=numeric_limits<int>::max(),mincol=numeric_limits<int>::max(),maxrow=numeric_limits<int>::min(),maxcol=numeric_limits<int>::min();
        int rsize=grid.size();
        int csize=grid[0].size();
        for(int i=0;i<rsize;i++)
        {
            for(int j=0;j<csize;j++)
            {
                if(grid[i][j]==1)
                {
                    minrow=min(minrow,i);
                    maxrow=max(maxrow,i);
                    mincol=min(mincol,j);
                    maxcol=max(maxcol,j);
                }
            }
        }
        return((maxrow-minrow+1)*(maxcol-mincol+1));
    }
};