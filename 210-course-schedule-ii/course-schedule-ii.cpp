class Solution {
public:
    bool helper(vector<vector<int>>& graph,vector<int>&visited,vector<int>&path,int curr,vector<int>&ans){
        visited[curr]=1;
        path[curr]=1;
        for(auto ch:graph[curr]){
            if(!visited[ch]){
                if(helper(graph,visited,path,ch,ans))return true;
            }
            else if(path[ch]){
                return true;
            }
        }
        path[curr]=0;
        ans.push_back(curr);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans,visited(numCourses,0),path(numCourses,0);
        vector<vector<int>>mat(numCourses);
        for(auto ch:prerequisites){
            int u=ch[0];
            int v=ch[1];
            mat[v].push_back(u);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(helper(mat,visited,path,i,ans))return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};