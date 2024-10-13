class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>ht;
        for(int i=0;i<nums.size();i++)
        {
            ht[nums[i]]++;
        }
        for(auto ch:ht)
        {
            if(ch.second>=2)
            {
                return ch.first;
            }
        }
        return -1;
    }
};