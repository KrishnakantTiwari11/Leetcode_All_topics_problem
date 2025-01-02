class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int temp=target-nums[i];
            if(mp.find(temp)!=mp.end()){
                return{mp[temp],i};
                break;
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};