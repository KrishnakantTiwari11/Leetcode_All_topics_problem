class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp,
                int index) {
        if (index == nums.size()) {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        helper(nums, res, temp, index + 1);
        temp.pop_back();
        helper(nums, res, temp, index + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        helper(nums,res,temp,0);
        return res;
    }
};