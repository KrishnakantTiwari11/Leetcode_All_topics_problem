class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size=nums.size();
        int n=size/2;
        int count = 0;
        int ans=0;
        if(nums.size()==1)
        {
            return nums[0];
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                count++;
                if(count>=n)
                {
                    ans= nums[i];
                }
            }
            else
            {
                count=0;
            }
        }
        return ans;
    }
};