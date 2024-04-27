class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        if(nums.size()==1)
        {
            return {};
        }
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(freq[nums[i]]==2)
            {
                   ans.push_back(nums[i]);
                   freq[nums[i]]--;
            }
        }
        return ans;
    }
};