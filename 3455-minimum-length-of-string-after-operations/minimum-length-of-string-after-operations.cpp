class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>left;
        unordered_map<char,int>right;
        int n=s.length();
        for(int i=0;i<n;i++){
            right[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(right.find(s[i])==right.end())continue;
            right[s[i]]--;
            if(right[s[i]]==0)right.erase(s[i]);
            if(left.find(s[i])!=left.end() && right.find(s[i])!=right.end()){
                left[s[i]]--;
                right[s[i]]--;
                if(left[s[i]]==0)left.erase(s[i]);
                if(right[s[i]]==0)right.erase(s[i]);
            }
            left[s[i]]++;
        }
        int ans=0;
        for(auto ch:left){
            ans+=ch.second;
        }
        return ans;
    }
};