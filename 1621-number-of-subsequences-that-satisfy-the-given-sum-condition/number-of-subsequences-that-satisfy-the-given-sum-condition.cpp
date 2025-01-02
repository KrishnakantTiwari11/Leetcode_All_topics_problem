class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>power(n,1);
        int count=0;
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2)%MOD;
        }
        int l=0,r=n-1;
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                count=(count+power[r-l])%MOD;
                l++;
            }else{
                r--;
            }
        }
        return count;
    }
};