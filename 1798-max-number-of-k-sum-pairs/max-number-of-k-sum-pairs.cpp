class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto ch : nums) {
            mp[ch]++;
        }
        int res = 0;
        for (auto ch : nums) {
            int diff = k - ch;
            if (mp.find(diff) != mp.end() && mp[diff] > 0 && mp[ch] > 0 &&
                !(diff == ch && mp[diff] <= 1)) {
                res++;
                mp[diff]--;
                mp[ch]--;
            }
        }
        return res;
    }
};