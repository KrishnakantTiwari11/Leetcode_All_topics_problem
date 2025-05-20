class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        // dist[node][stops] = min cost to reach node with stops
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        // {cost, node, stops}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();

            if (node == dst) return cost;
            if (stops > k) continue;

            for (auto& [next, price] : graph[node]) {
                if (cost + price < dist[next][stops + 1]) {
                    dist[next][stops + 1] = cost + price;
                    pq.push({dist[next][stops + 1], next, stops + 1});
                }
            }
        }

        return -1;
    }
};
