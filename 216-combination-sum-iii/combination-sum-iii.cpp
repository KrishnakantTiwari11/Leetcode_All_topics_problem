class Solution {
public:
    void cs(vector<vector<int>>&res,vector<int>&temp,int k,vector<int>&nums,int sum,int i,int n){
        if(sum==n && temp.size()==k){
            res.push_back(temp);
            return;
        }
        if (i >= nums.size() || temp.size() > k || sum > n)
            return;
        temp.push_back(nums[i]);
        cs(res,temp,k,nums,sum+nums[i],i+1,n);
        temp.pop_back();
        cs(res,temp,k,nums,sum,i+1,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums(9);
        for(int i=0;i<9;i++){
            nums[i]=i+1;
        }
        vector<vector<int>>res;
        vector<int>temp;
        cs(res,temp,k,nums,0,0,n);
        return res;
    }
};