class Solution {
public:
    void helper(vector<vector<int>>& adj,vector<int>&visited,int start){
        visited[start]=1;
        int n=adj.size();
        for(int i=0;i<n;i++){
            if(visited[i]==0 && adj[start][i]==1){
                helper(adj,visited,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>visited(n,0);
        int res=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                res++;
                helper(isConnected,visited,i);
            }
        }
        return res;
    }
};