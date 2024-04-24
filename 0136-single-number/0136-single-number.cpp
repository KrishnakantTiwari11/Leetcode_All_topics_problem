class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        int ans=0;
        if(nums.size()==1)
        {
            return nums[0];
        }
        else if(nums[0]!=nums[1])
             {
                 return nums[0];
            
             }
        else if(nums[n]!=nums[n-1])
            {
                return nums[n];
            }
        for(int i=1;i<nums.size()-1;i++)
        {
             
            if(nums[i]!=nums[i+1] && nums[i]!=nums[i-1])
            {
                ans= nums[i];
                break;
            }
        }
        return ans;
       
    }
};