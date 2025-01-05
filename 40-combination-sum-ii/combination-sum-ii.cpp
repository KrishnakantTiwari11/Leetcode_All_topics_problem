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
       for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]){
                continue;
            }
            temp.push_back(nums[j]);
            cs(res,target,temp,nums,j+1,sum+nums[j]);
            temp.pop_back();
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          sort(candidates.begin(),candidates.end());
          vector<vector<int>>res;
          vector<int>temp;
          cs(res,target,temp,candidates,0,0);
          return res;
    }
};