class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)q.push({{i,j},0});
                if(grid[i][j]==1)fresh++;
            }
        }
        int res=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int time=q.front().second;
            q.pop();
            res=max(res,time);
            if(r-1>=0 && grid[r-1][c]==1 && !visited[r-1][c]){
                visited[r-1][c]=1;
                q.push({{r-1,c},time+1});
                fresh--;
            }
            if(r+1<m && grid[r+1][c]==1 && !visited[r+1][c]){
                visited[r+1][c]=1;
                q.push({{r+1,c},time+1});
                fresh--;
            }
            if(c-1>=0 && grid[r][c-1]==1 && !visited[r][c-1]){
                visited[r][c-1]=1;
                q.push({{r,c-1},time+1});
                fresh--;
            }
            if(c+1<n && grid[r][c+1]==1 && !visited[r][c+1]){
                visited[r][c+1]=1;
                q.push({{r,c+1},time+1});
                fresh--;
            }
        }
        if(fresh==0)return res;
        return -1;
    }
};