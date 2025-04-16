class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long res = 0, pairs = 0;
        int n = nums.size(), left = 0;

        for (int right = 0; right < n; ++right) {
            int num = nums[right];
            pairs += freq[num];
            freq[num]++;

            while (pairs >= k) {
                res += (n - right);
                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
        }

        return res;
    }
};
