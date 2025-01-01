class Solution {
public:
    void sub(int i,vector<int>& temp,vector<vector<int>>& res,vector<int>& nums){
        if(i>=nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        sub(i+1,temp,res,nums);
        temp.pop_back();
        sub(i+1,temp,res,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>res;
        sub(0,temp,res,nums);
        return res;
    }
};