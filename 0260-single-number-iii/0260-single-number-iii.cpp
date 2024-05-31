class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                {
                      nums[i]=-9;
                      nums[j]=-9;
                }
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=-9)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};