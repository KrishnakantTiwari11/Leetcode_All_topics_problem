class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int gk=0;
        unordered_set<int>mp;
        for(auto ch:nums){
            mp.insert(ch);
        }
        if(mp.size()==1 && nums[0]==k)return 0;
        for(auto ch:mp){
            if(ch>k)gk++;
            if(k>ch)return -1;
        }
        return gk==0?-1:gk;
    }
};