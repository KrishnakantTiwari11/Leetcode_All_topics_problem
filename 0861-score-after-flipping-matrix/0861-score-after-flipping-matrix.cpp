class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        
        auto Fliprow=[&](int row)
        {
            for(int i=0;i<cols;i++)
            {
                  grid[row][i]=1-grid[row][i];
            }
        };
        
        auto Flipcol=[&](int col)
        {
            for(int i=0;i<rows;i++)
            {
                grid[i][col]=1-grid[i][col];
            }
        };
        
        auto addbin=[&](const vector<int>&nums)
        {
            int res=0;
            for(int num:nums)
            {
                 res=res*2+num;
            }
            return res;
        };
        
        for(int i=0;i<rows;i++)
        {
            if(grid[i][0]==1)
            {
                 Fliprow(i);
            }
        }
        
        for(int i=0;i<cols;i++)
        {
            int countzero=0;
            int countone=0;
            for(int j=0;j<rows;j++)
            {
                if(grid[j][i]==1)
                {
                    countone++;
                }
                else
                {
                     countzero++;
                }
            }
            if(countzero>countone)
            {
                Flipcol(i);
            }
        }
        
        int totalscore=0;
        for(int i=0;i<rows;i++)
        {
            totalscore=totalscore+addbin(grid[i]);
        }
        return totalscore;
    }
};