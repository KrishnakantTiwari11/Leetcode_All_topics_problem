class Solution {
public:
    void subset(vector<vector<int>>&res,vector<int>& temp,vector<int>&nums,int ind){
        res.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            subset(res,temp,nums,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        subset(res,temp,nums,0);
        return res;
    }
};