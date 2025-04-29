class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxi=LLONG_MIN,res=0;
        for(auto num:nums){
            maxi=max(maxi,(long long)num);
        }
        int n=nums.size();
        int count=0,j=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi)count++;
            while(count>=k){
                res+=(n-i);
                if(nums[j]==maxi)count--;
                j++;
            }
        }
        return res;
    }
};