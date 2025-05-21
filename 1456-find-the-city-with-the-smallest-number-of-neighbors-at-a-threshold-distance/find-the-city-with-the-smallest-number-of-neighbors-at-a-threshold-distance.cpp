class Solution {
public:
    vector<int> djkstra(vector<vector<pair<int, int>>>& mat, int src) {
        int n = mat.size();
        vector<int> distance(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        q.push({0, src});
        distance[src] = 0;
        while (!q.empty()) {
            int curr = q.top().second;
            int dist = q.top().first;
            q.pop();
            for (auto neigh : mat[curr]) {
                int wt = neigh.second;
                int next = neigh.first;
                if (distance[curr] + wt < distance[next]) {
                    distance[next] = distance[curr] + wt;
                    q.push({distance[next], next});
                }
            }
        }
        return distance;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> path(n);
        vector<vector<pair<int, int>>> mat(n);
        int r_city=0,r_city_num=INT_MAX;
        for (auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            mat[u].push_back({v, w});
            mat[v].push_back({u, w});
        }
        for (int i = 0; i < n; i++) {
            path[i] = djkstra(mat, i);
            int temp = 0;
            for (int j = 0; j < n; j++) {
                if (i!=j && path[i][j] <= distanceThreshold) {
                    temp++;
                }
            }
            if (temp <= r_city_num) {
                r_city = i;
                r_city_num = temp;
            }
        }
        return r_city;
    }
};