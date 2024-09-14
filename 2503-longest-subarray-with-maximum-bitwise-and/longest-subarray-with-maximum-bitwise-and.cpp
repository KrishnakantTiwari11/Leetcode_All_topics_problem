class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxe=*max_element(nums.begin(),nums.end());
        int subarray=0;
        int ans=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==maxe)
            {
                subarray++;
                ans=max(ans,subarray);
            }
            else
            {
                subarray=0;
            }
        }
        return ans;
    }
};