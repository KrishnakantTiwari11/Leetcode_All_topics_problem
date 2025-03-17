class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto ch:nums){
            mp[ch]++;
        }
        if(mp.size()==nums.size())return false;
        for(auto ch:mp){
            if(ch.second%2!=0)return false;
        }
        return true;
    }
};