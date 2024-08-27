
class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int ans = INT_MAX;
        int n = piles.size();
        int mini = 1;
        int maxi = *max_element(piles.begin(), piles.end());

        while (mini <= maxi) {
            int mid = mini + (maxi - mini) / 2;
            int ite = 0;
            double temp = 0;
            
           
            while (ite < n) {
                temp +=ceil(double(piles[ite]) / mid);
                ite++;
            }
            
            if (temp <= h) {
                maxi = mid - 1;
                ans = std::min(ans, mid);
            } else {
                mini = mid + 1;
            }
        }

        return ans;
    }
};
