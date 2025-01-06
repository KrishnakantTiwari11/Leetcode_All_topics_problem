class Solution {
public:
    void subset(vector<vector<int>>&res,vector<int>& temp,vector<int>&nums,int i){
        if(i>=nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        subset(res,temp,nums,i+1);
        temp.pop_back();
        subset(res,temp,nums,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        subset(res,temp,nums,0);
        return res;
    }
};