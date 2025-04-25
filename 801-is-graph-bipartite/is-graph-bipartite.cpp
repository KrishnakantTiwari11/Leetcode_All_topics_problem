class Solution {
public:
    bool helper(vector<vector<int>>& graph,vector<int>&visited,int curr,int par){
        if(par!=-2){
            visited[curr]=-visited[par];
        }
        else{
            visited[curr]=1;
        }
        for(auto neigh:graph[curr]){
            if(!visited[neigh]){
                if(!helper(graph,visited,neigh,curr))return false;
            }
            else if(visited[neigh]==visited[curr]){
                return false;
            }
        }
        return true;        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        for(int i=0;i<m;i++){
            vector<int>visited(m,0);
            if(!visited[i]){
                if(!helper(graph,visited,i,-2))return false;
            }
        }
        return true;
    }
};