class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=-1;
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                return mid;
            }
            else if(target>nums[mid])
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};