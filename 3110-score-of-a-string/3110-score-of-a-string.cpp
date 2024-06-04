class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        int l=0;
        int r=1;
        while(r<s.length())
        {
            ans=ans+abs(static_cast<int>(s[l])-static_cast<int>(s[r]));
            l++;
            r++;
        }
        return ans;
    }
};