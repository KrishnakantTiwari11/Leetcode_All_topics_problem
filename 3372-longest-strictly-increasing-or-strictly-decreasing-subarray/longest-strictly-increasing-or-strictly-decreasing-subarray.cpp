class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=0;
        int dec=0;
        int maxinc=0,maxdec=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc++;
                maxinc=max(inc,maxinc);
            }
            else{
                inc=0;
            }

            if(nums[i]<nums[i-1]){
                dec++;
                maxdec=max(dec,maxdec);
            }
            else{
                dec=0;
            }
        }
        return max(maxinc,maxdec)+1;
    }
};