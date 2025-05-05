class Solution {
public:
    bool helper(vector<vector<int>>&mat,vector<int>&node,vector<int>&path,int curr){
        path[curr]=1;
        node[curr]=1;
        for(auto ch:mat[curr]){
            if(!node[ch]){
                if(!helper(mat,node,path,ch))return false;
            }
            else if(path[ch]){
                return false;
            }
        }
        path[curr]=0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>mat(n);
        for(auto pre:prerequisites){
            int u=pre[0];
            int v=pre[1];
            mat[v].push_back(u);
        }
        vector<int>node(n,0);
        vector<int>path(n,0);
        for(int i=0;i<n;i++){
            if(!node[i]){
                if(!helper(mat,node,path,i))return false;
            }
        }
        return true;
    }
};