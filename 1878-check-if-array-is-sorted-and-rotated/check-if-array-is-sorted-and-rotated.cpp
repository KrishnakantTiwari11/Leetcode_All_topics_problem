class Solution {
public:
    bool check(vector<int>& nums) {
        int min_ind=0;
        int min_num=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
           else if(nums[i]<=min_num){
                min_num=nums[i];
                min_ind=i;
            }
        }
        int j=min_ind;
        for(int i=0;i<n-1;i++){
            if(nums[j%n]>nums[(j+1)%n]){
                return false;
            }
            j++;
        }
        return true;
    }
};