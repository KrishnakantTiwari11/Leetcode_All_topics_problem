class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>mat(n);
        vector<int>inDegree(n,0),res;
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                int u=i;
                int v=graph[i][j];
                mat[v].push_back(u);
                inDegree[u]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            res.push_back(curr);
            for(auto ch:mat[curr]){
                inDegree[ch]--;
                if(inDegree[ch]==0)q.push(ch);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};