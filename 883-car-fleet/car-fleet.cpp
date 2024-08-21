class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; i++) {
            double timeToTarget = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], timeToTarget};
        }
        
        sort(cars.begin(), cars.end());
        
        int fleets = 0;
        stack<double> st;
        
        for (int i = n - 1; i >= 0; i--) {
            double timeToTarget = cars[i].second;
            
            if (st.empty() || timeToTarget > st.top()) {
                fleets++;
                st.push(timeToTarget);
            }
        }
        
        return fleets;
    }
};
