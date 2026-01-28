class Solution {
private:
int currTime = 1;
public:
void helper(vector<vector<int>>&adj,vector<vector<int>>&res,vector<int>&tin,vector<int>&low,int parent,int node,vector<int>&visited){
    visited[node]=1;
    tin[node]=low[node]=currTime;
    currTime++;
    for(auto neigh:adj[node]){
    if(neigh==parent)continue;
    if(!visited[neigh]){
    helper(adj,res,tin,low,node,neigh,visited);
      low[node]=min(low[neigh],low[node]);
      if(tin[node]<low[neigh]){
      res.push_back({node,neigh});}
    }else{
      low[node]=min(low[neigh],low[node]);
      }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n),res;
        vector<int>tin(n),low(n),visited(n,0);
        for(auto edge:connections){
        int u=edge[0],v=edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        }
        helper(adj,res,tin,low,-1,0,visited);
        return res;
    }
};