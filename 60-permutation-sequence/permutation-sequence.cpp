class Solution {
public:
   bool helper(vector<vector<int>>&res,vector<int>&temp,vector<int>&visited,vector<int> & nums,int & k){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            k--;
            if(k==0)return true;
            return false;
        }
        for(int i=0;i<nums.size();i++){
           if(!visited[i]){
             temp.push_back(nums[i]);
             visited[i]=1;
             if(helper(res,temp,visited,nums,k))return true;
             temp.pop_back();
             visited[i]=0;
           }
        }
        return false;
    }
    string getPermutation(int n, int k) {
         vector<int> nums(n);
        vector<int>visited(n,0);
        vector<vector<int>>res;
        vector<int>temp;
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        helper(res,temp,visited,nums,k);
        vector<int>result=res.back();
        string ans="";
        for(int i=0;i<n;i++){
            ans+=to_string(result[i]);
        }
        return ans;
    }
};