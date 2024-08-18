class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0]=1;
        int p2=0,p3=0,p5=0;
        for(int i=1;i<n;i++)
        {
            int two_mul=dp[p2]*2,three_mul=dp[p3]*3,five_mul=dp[p5]*5;
            int ugly_num=min(two_mul,min(three_mul,five_mul));
            dp[i]=ugly_num;
            if(dp[i]==two_mul)
            {
                p2++;
            }
            if(dp[i]==three_mul)
            {
                p3++;
            }
            if(dp[i]==five_mul)
            {
                p5++;
            }
        }
        return dp[n-1];
    }
};