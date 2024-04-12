
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        bool fv=false;
        int n=s.length()-1;
        for(int i=n;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                ans++;
                fv=true;
            }
            else{
                if(fv)
                {
                    break;
                }
            }
        }
        return ans;
    }
};