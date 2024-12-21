class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int side_sum=nums[0]+nums[2];
        int mid=nums[1];
        int res=0;
        if(mid==side_sum*2)
        {
            res++;
        }
        for(int i=3;i<n;i++)
        {
            side_sum=nums[i]+nums[i-2];
            mid=nums[i-1];
            if(mid==side_sum*2)
            {
                res++;
            }
        }
        return res;
    }
};