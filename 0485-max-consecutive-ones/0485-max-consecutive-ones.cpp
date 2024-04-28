class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currcount =0;
        int lastcount=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                currcount++;
            }
           else
            {
                lastcount=max(lastcount,currcount);
                currcount=0;
            }
        
        }
        
        return max(lastcount,currcount);
        
        
        
    }
};