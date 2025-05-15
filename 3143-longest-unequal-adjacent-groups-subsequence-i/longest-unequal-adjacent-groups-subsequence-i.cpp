class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>res;
        int n=groups.size(),prev_val=-1;
        for(int i=0;i<n;i++){
            if(i==0 || groups[i]!=prev_val)prev_val=groups[i],res.push_back(words[i]);
        }
        return res;
    }
};