class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_set<string>mp(nums.begin(),nums.end());
        string ans(n,'0');
        if(mp.find(ans)==mp.end())return ans;
        for(int i=0;i<n;i++){
            ans[i]='1';
            if(mp.find(ans)==mp.end())return ans;
        }
        return "";
    }
};