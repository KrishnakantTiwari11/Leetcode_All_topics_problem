class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> workers;
        int n = quality.size();
        for(int i=0; i<n; i++){
            workers.push_back({(double)wage[i] / (double)quality[i], quality[i]});
        }
        sort(workers.begin(), workers.end());
        priority_queue<int>q;
        double q_sum = 0, ans=DBL_MAX;
        for(auto worker: workers){
            q_sum += worker.second;
            q.push(worker.second);
            if(q.size() > k){
                q_sum -= q.top();
                q.pop();
            }
            if(q.size() == k)
                ans = min(ans, worker.first*q_sum);
        }
        return ans;
    }
};