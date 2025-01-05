class Solution {
public:
    void cs(vector<vector<int>>& res, vector<int>& temp, int ind, int sum,
            int target,vector<int>&nums) {
                if(sum==target){
                    res.push_back(temp);
                    return;
                }
                if(sum>target || ind>=nums.size())return;
                for(int i=ind;i<nums.size();i++){
                    if(i>ind && nums[i]==nums[i-1]){
                        continue;
                    }
                    sum+=nums[i];
                    temp.push_back(nums[i]);
                    cs(res,temp,i+1,sum,target,nums);
                    temp.pop_back();
                    sum-=nums[i];
                }
            }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>res;
        vector<int>temp;
        cs(res,temp,0,0,target,candidates);
        return res;
    }
};