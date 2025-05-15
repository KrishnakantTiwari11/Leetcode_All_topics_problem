class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>res;
        int n=groups.size();
        int prev_val=-1;
        for(int i=0;i<n;i++){
            if(i==0){
                prev_val=groups[i];
                res.push_back(words[i]);
            }
            else if(groups[i]!=prev_val){
                res.push_back(words[i]);
                prev_val=groups[i];
            }
        }
        return res;
    }
};