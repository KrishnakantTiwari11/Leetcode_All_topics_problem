class Solution {
public:
    void helper(vector<vector<int>>&res,vector<int>&temp,vector<int>&nums,int ind){
        if(ind==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            helper(res,temp,nums,ind+1);
            swap(nums[ind],nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        vector<int>temp;
        helper(res,temp,nums,0);
        return res;
    }
};