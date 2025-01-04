class Solution {
public:
    void helper(int i,vector<vector<int>>&res,vector<int>&temp,vector<int>&nums,int target,int&sum){
        if(sum>target){
            return;
        }
        if(i>=nums.size()){
            if(sum==target){
                res.push_back(temp);
            }
            return;
        }
        temp.push_back(nums[i]);
        sum+=nums[i];
        helper(i,res,temp,nums,target,sum);
        temp.pop_back();
        sum-=nums[i];
        helper(i+1,res,temp,nums,target,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        int sum=0;
        helper(0,res,temp,candidates,target,sum);
        return res;
    }
};