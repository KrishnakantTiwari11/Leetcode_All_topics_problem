class Solution {
public:
    void cs(vector<vector<int>>& res, int target, vector<int>& temp,
            vector<int>& nums, int i) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        if (i >= nums.size() || target<0) {
            return;
        }
        temp.push_back(nums[i]);
        cs(res, target-nums[i], temp, nums, i);
        temp.pop_back();
        cs(res, target, temp, nums, i + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<vector<int>>res;
          vector<int>temp;
          cs(res,target,temp,candidates,0);
          return res;
    }
};