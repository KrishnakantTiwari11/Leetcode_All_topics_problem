class Solution {
public:
    long long minimumSteps(string s) {
        long long swap=0;
        int ps=0;
        int n=s.length();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                swap+=(n-1)-i-ps;
                ps++;
            }
        }
        return swap;
    }
};