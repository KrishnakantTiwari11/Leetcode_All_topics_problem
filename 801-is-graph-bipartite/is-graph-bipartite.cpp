class Solution {
public:
    bool helper(vector<vector<int>>& graph,vector<int>&visited,int curr,int par){
        if(par==-1){
            visited[curr]=1;
        }
        else{
            visited[curr]=-visited[par];
        }
        for(auto ch:graph[curr]){
            if(!visited[ch]){
                if(!helper(graph,visited,ch,curr))return false;
            }
            else if(visited[curr]==visited[ch]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(!helper(graph,visited,i,-1))return false;
            }
        }
        return true;
    }
};