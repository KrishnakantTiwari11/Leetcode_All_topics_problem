class Solution {
public:
    void subset(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums,
                int i) {
        res.push_back(temp);
        if (i >= nums.size()) {
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) {
                continue;
            }
            temp.push_back(nums[j]);
            subset(res, temp, nums, j + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        subset(res, temp, nums, 0);
        return res;
    }
};
