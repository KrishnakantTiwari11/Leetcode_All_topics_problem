class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>mat(n);
        vector<int>inDegree(n,0),res;
        queue<int>q;
        for(int i=0;i<n;i++){
            for(auto num:graph[i]){
                mat[num].push_back(i);
                inDegree[i]++;
            }
        }
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            res.push_back(curr);
            for(auto neigh:mat[curr]){
                inDegree[neigh]--;
                if(inDegree[neigh]==0)q.push(neigh);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};