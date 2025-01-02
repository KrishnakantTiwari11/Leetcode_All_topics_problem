class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n);
        int ans=0;
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        unordered_map<int,int>mp;
        for(auto ch:prefix){
            if(ch==k){
                ans++;
            }
            if(mp.find(ch-k)!=mp.end()){
                ans+=mp[ch-k];
            }
            mp[ch]++;
        }
        return ans;
    }
};