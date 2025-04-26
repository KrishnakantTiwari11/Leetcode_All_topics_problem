class Solution {
public:
    bool helper(vector<vector<int>>&mat,vector<int>&visited,vector<int>&path,int curr){
        visited[curr]=1;
        path[curr]=1;
        for(auto neigh:mat[curr]){
            if(!visited[neigh]){
                if(!helper(mat,visited,path,neigh))return false;
            }
            else if(path[neigh]){
                return false;
            }
        }
        path[curr]=0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>visited(n,0),path(n,0);
        vector<vector<int>>mat(n);
        for(auto edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            mat[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(!helper(mat,visited,path,i))return false;
            }
        }
        return true;
    }
};