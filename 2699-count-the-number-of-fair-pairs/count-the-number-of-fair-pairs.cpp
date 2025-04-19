class Solution {
public:
    long long helper(vector<int>&nums,int comp){
        int j=nums.size()-1,i=0;
        long long res=0;
        while(i<j){
            if(nums[i]+nums[j]>=comp){
                res+=j-i;
                j--;
            }
            else{
                i++;
            }
        }
        return res;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return helper(nums,lower)-helper(nums,(long long)upper+1);
    }
};