class Solution {
public:
    void cs(vector<vector<int>>& res, int target, vector<int>& temp,
            vector<int>& nums, int i,int sum) {
        if (sum==target) {
            res.push_back(temp);
            return;
        }
        if (i >= nums.size() || sum>target) {
            return;
        }
        temp.push_back(nums[i]);
        cs(res, target, temp, nums, i,sum+nums[i]);
        temp.pop_back();
        cs(res, target, temp, nums, i + 1,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<vector<int>>res;
          vector<int>temp;
          cs(res,target,temp,candidates,0,0);
          return res;
    }
};