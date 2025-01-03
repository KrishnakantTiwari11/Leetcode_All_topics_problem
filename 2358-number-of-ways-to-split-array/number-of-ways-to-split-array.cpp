class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long left_sum=nums[0];
        long long right_sum=0;
        int count=0;
        for(int i=n-1;i>=1;i--){
            right_sum+=nums[i];
        }
        for(int i=1;i<n;i++){
            if(left_sum>=right_sum)count++;
            left_sum+=nums[i];
            right_sum-=nums[i];
        }
        return count;
    }
};