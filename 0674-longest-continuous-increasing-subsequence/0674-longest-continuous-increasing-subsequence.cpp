class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int l=0;
        int r=1;
        int res=1;
        int newres=1;
        while(r<nums.size())
        {
            if(nums[l]<nums[r])
            {
                newres++;
            }
            else
            {
                res=max(res,newres);
                newres=1;
            }
            res=max(res,newres);
            r++;
            l++;
            
        }
        return res;
    }
};