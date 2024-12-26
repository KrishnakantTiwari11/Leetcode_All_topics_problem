class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int index = nums.size() - 1;
        int curr_sum = 0;
        unordered_map<string, int> memo;
        return dp(nums, S, index, curr_sum, memo);
    }
    
private:
    int dp(vector<int>& nums, int target, int index, int curr_sum, unordered_map<string, int>& memo) {
        string key = to_string(index) + "," + to_string(curr_sum);
        
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        if (index < 0 && curr_sum == target) {
            return 1;
        }
        if (index < 0) {
            return 0;
        }
        
        int positive = dp(nums, target, index - 1, curr_sum + nums[index], memo);
        int negative = dp(nums, target, index - 1, curr_sum - nums[index], memo);
        
        memo[key] = positive + negative;
        return memo[key];
    }
};
