class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>hash;
        int ans=0;
        for(auto&num:nums)
        {
            hash[num]++;
        }
        for(auto &[x,y]:hash)
        {
            if(y==1)
            {
               ans=x;
                break;
            }
        }
        return ans;
    }
};