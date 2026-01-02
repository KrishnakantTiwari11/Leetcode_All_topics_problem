class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp,
                int index) {
        res.push_back(temp);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            temp.push_back(nums[i]);
            helper(nums, res, temp, i+1);      
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        helper(nums, res, temp, 0);
        return res;
    }
};