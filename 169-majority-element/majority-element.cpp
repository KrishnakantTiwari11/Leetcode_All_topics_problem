class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto ch : nums) {
            mp[ch]++;
        }
        int res = -1;
        int maxCount = 0;
        for (auto ch : mp) {
            int key = ch.first;
            int freq = ch.second;
            if (freq > maxCount) {
                maxCount = freq;
                res = key;
            }
        }
        return res;
    }
};