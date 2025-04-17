class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        long long res=0,n=nums.size();
        for(int i=0;i<n;i++){
            res+=(i-mp[nums[i]-i]);
            mp[nums[i]-i]++;
        }
        return res;
    }
};