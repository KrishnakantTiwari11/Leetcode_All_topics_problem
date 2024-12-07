class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int>mp;
        for(auto ch:nums)
            {
                mp[ch]++;
            }
       for(auto ch:mp)
           {
               if(ch.first>k)
               {
                   count++;
               }
               else if(ch.first<k)
               {
                return -1;
               }
           }
        return count;
    }
};
