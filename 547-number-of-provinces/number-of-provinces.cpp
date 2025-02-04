class Solution {
public:
    void dfs(int start,vector<int>&visited,vector<vector<int>>& isConnected){
          visited[start]=1;
          for(int i=0;i<isConnected.size();i++){
            if(isConnected[start][i]==1 && visited[i]==0){
                dfs(i,visited,isConnected);
            }
          }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res=0;
        int n=isConnected.size();
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                res++;
                dfs(i,visited,isConnected);
            }
        }
        return res;
    }
};