class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>hash;
        for(auto&num:nums)
        {
            hash[num]++;
        }
        for(auto &[x,y]:hash)
        {
            if(y==1)
            {
                ans.push_back(x);
            }
            if(ans.size()==2)
            {
                break;
            }
        }
        return ans;
        
    }
};