class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ans = 0;
        int maxAdditionalSatisfied = 0;
        int currentAdditional = 0;
        
        // Calculate initial satisfied customers and potential additional if all 'grumpy' are flipped
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                ans += customers[i];
            } else {
                currentAdditional += customers[i];
            }
            
            if (i >= minutes) {
                currentAdditional -= grumpy[i - minutes] * customers[i - minutes];
            }
            
            maxAdditionalSatisfied = max(maxAdditionalSatisfied, currentAdditional);
        }
        
        return ans + maxAdditionalSatisfied;
    }
};
