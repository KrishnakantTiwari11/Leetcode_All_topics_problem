class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>hash;
        for(auto&num:nums)
        {
            hash[num]++;
        }
        vector<int>ans;
        for(auto&[x,y]:hash)
        {
            if(y==2)
            {
                ans.push_back(x);
            }
        }
        int n=nums.size();
        for(int i=1;i<n+1;i++)
        {
            if(hash[i]==0)
            {
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};