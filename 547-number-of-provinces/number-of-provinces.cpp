class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int curr,int n) {
        visited[curr]=1;
        for(int i=0;i<n;i++){
            if(!visited[i] && isConnected[curr][i]){
                dfs(isConnected,visited,i,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(),res=0;
        vector<int> visited(n);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                res++;
                dfs(isConnected,visited,i,n);
            }
        }
        return res;
    }
};