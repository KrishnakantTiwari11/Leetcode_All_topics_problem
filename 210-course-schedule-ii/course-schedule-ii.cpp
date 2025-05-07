class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>mat(n);
        for(auto pre:prerequisites){
            int u=pre[0];
            int v=pre[1];
            mat[v].push_back(u);
        }
        vector<int>inDegree(n);
        for(auto vec:mat){
            for(int i=0;i<vec.size();i++){
                inDegree[vec[i]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int>res;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            res.push_back(curr);
            for(auto ch:mat[curr]){
                inDegree[ch]--;
                if(inDegree[ch]==0){
                    q.push(ch);
                }
            }
        }
        if(res.size()==n)return res;
        return {};
    }
};