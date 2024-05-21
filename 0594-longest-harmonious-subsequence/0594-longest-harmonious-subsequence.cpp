class Solution {
public:
    int findLHS(vector<int>& nums) {
        int l=0,r=1,res=0;
        sort(nums.begin(),nums.end());
        while(r<nums.size())
        {
             if(nums[r]-nums[l]==1)
             {
                 res=max(res,r-l+1);
             }
            while(nums[r]-nums[l]>1)
            {
                l++;
            }
            r++;
        }
        return res;
    }
};