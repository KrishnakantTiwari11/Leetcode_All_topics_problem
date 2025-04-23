class Solution {
public:
    bool helper(vector<vector<int>>& graph,vector<int>&visited,int curr,int par){
            if(par!=-1){
                visited[curr]=-visited[par];
            }
            else{
                visited[curr]=1;
            }
            for(auto ch:graph[curr]){
                if(visited[ch]==0){
                    if(!helper(graph,visited,ch,curr))return false;
                }
                else if(visited[ch]==visited[curr]){
                    return false;
                }
            }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
               if(!helper(graph,visited,i,-1))return false;
            }
        }
        return true;
    }
};