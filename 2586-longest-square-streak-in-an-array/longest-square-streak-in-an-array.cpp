class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        int res=0;
        sort(nums.begin(),nums.end());
        for(int num:nums)
        {
            int ssqrt=sqrt(num);
            if(ssqrt*ssqrt==num && mp.find(ssqrt)!=mp.end())
            {
                mp[num]=mp[ssqrt]+1;
                res=max(res,mp[num]);
            }
            else
            {
                mp[num]=1;
            }
        }
        if(res==0 or res==1)
        {
            return -1;
        }
        return res;
    }
};