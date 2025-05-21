class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>mat(n+1);
        for(auto edge:times){
            int u=edge[0],v=edge[1],w=edge[2];
            mat[u].push_back({v,w});
        }
        vector<int> distance(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        distance[k] = 0;
        q.push({0, k});
        while (!q.empty()){
            int curr = q.top().second;
            int dist = q.top().first;
            q.pop();
            for(auto neigh:mat[curr]){
                int next = neigh.first;
                int wt = neigh.second;
                
                if(distance[curr] + wt < distance[next]){
                    distance[next] = distance[curr] + wt;
                    q.push({distance[next],next});
                }
            }
        }
        int res=INT_MIN;
        for(int i=1;i<=n;i++){
            if(distance[i] == INT_MAX)return -1;
            res = max(res,distance[i]);
        }
        return res;
    }
};