class Solution {
public:

   

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>>adj(n);
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]}); // adjNode,edgeWeight
        }

        vector<int>dist(n,INT_MAX);
        dist[src] =0;
        // priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        queue< pair<int,pair<int,int>> > pq;
        pq.push({0,{0,src}});

        while(pq.size()>0){
            auto p = pq.front();
            pq.pop();
            int d = p.first;
            int stops = p.second.first;
            int node = p.second.second;

            if(stops>k) continue;

            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;
                int newDist = d + edgeWt;

                if(newDist < dist[adjNode]){
                //    if(adjNode==dst && stops>k) continue;
                   dist[adjNode] = newDist;
                   pq.push({newDist,{stops+1,adjNode}});
                }
            }
        }
     
        
        if(dist[dst]==INT_MAX) return -1;
       
        return dist[dst];


    }
};