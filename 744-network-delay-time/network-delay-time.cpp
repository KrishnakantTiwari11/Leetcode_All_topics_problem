class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>mat(n+1);
        for(auto time:times){
            int u = time[0],v=time[1],w=time[2];
            mat[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>distance(n+1,INT_MAX);
        q.push({0,k});
        distance[k]=0;
        while(!q.empty()){
            int curr = q.top().second;
            int max_dist = q.top().first;
            q.pop();
            for(auto neigh:mat[curr]){
                int wt = neigh.second , next = neigh.first;
                if(distance[curr] + wt < distance[next]){
                    distance[next] = distance[curr] + wt;
                    q.push({distance[next],next});
                }
            }
        }
        int res;
        for(int i=1;i<=n;i++){
            if(distance[i] == INT_MAX)return -1;
            res = max(res,distance[i]);
        }
        return res;
    }
};