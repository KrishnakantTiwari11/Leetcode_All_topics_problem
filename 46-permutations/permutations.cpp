class Solution {
public:
    void helper(vector<vector<int>>&res,vector<int>&temp,vector<int>&visited,vector<int>&nums){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                temp.push_back(nums[i]);
                visited[i]=1;
                helper(res,temp,visited,nums);
                visited[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>visited(n,0);
        vector<vector<int>>res;
        vector<int>temp;
        helper(res,temp,visited,nums);
        return res;
    }
};