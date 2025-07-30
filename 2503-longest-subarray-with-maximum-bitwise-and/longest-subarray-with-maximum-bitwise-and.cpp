class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int subarray=0;
        int maxNum=*max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==maxNum){
                subarray++;
                ans=max(subarray,ans);
            }
            else{
                subarray=0;
            }
        }
        return ans;
    }
};