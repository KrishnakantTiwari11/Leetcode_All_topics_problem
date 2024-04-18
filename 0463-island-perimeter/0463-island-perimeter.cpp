class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
    
        
        int ans=0;
        int min=0;
        int res=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    ans+=1;
                    if(j!=0 && grid[i][j-1]==1)
                    {
                        min+=1;
                    }
                    if(i!=0 && grid[i-1][j]==1)
                    {
                        min+=1;
                    }
                    
                    
                }
            }
        }
        res=4*ans-2*min;
        return res;
        
    }
        
};