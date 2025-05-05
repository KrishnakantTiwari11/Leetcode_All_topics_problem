class Solution {
public:
     bool helper(vector<vector<int>>&mat,vector<int>&node,vector<int>&path,int curr,vector<int>&res){
        path[curr]=1;
        node[curr]=1;
        for(auto ch:mat[curr]){
            if(!node[ch]){
                if(!helper(mat,node,path,ch,res))return false;
            }
            else if(path[ch]){
                return false;
            }
        }
        path[curr]=0;
        res.push_back(curr);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>mat(n);
        for(auto pre:prerequisites){
            int u=pre[0];
            int v=pre[1];
            mat[v].push_back(u);
        }
        vector<int>node(n,0);
        vector<int>path(n,0);
        vector<int>res;
        for(int i=0;i<n;i++){
            if(!node[i]){
                if(!helper(mat,node,path,i,res))return {};
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
