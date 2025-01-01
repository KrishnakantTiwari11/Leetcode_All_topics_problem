class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int zero=0,one=0;
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                one++;
            }
        }
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                zero++;
            }
            else{
                one--;
            }
            res=max(res,zero+one);
        }
        return res;
    }
};