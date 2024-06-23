class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        double ans=numeric_limits<double>::infinity();
        int l=0;
        int r=nums.size()-1;
        while(l<r)
        {
            double div=static_cast<double>(nums[l]+nums[r])/2.0;
            ans=min(ans,div);
            l++;
            r--;
            
        }
        return ans;
        
    }
};