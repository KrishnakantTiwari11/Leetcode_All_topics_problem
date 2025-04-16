class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size(),left=0,pairs=0;
        long long res=0;
        unordered_map<int,int>mp;
        for(int right=0;right<n;right++){
            int num=nums[right];
            pairs+=mp[num];
            mp[num]++;
            while(pairs>=k){
                res+=(n-right);
                mp[nums[left]]--;
                pairs-=mp[nums[left]];
                left++;
            }
        }
        return res;
    }
};