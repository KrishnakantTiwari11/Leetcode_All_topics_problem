class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int res = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                res = min(res,i-mp[nums[i]]);
                if(res<=k){
                    return true;
                }
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};