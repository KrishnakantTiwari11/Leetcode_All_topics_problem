class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        vector<pair<int, double>> car(n);
        
        for (int i = 0; i < n; i++) {
            double timeToTarget = (double)(target - position[i]) / speed[i];
            car[i] = {position[i], timeToTarget};
        }
        
        sort(car.begin(), car.end(), [](const auto &a, const auto &b) {
            return a.first > b.first;
        });
        
        int fleets = 0;
        double currentFleetTime = 0.0;
        
        for (int i = 0; i < n; i++) {
            if (car[i].second > currentFleetTime) {
                fleets++;
                currentFleetTime = car[i].second;
            }
        }
        
        return fleets;
    }
};
