class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int>prefix(n+1,0);
        for(auto ch:shifts){
            int dir=ch[2];
            int f=ch[0];
            int s=ch[1];
            if(dir==0){
                prefix[f]--;
                prefix[s+1]++;
            }
            else{
                prefix[f]++;
                prefix[s+1]--;
            }
        }
        for(int i=1;i<prefix.size();i++){
            prefix[i]+=prefix[i-1];
        }
        for(int i=0;i<n;i++){
            int shift=(s[i]-'a'+prefix[i]%26)%26;
            if(shift<0)shift+=26;
            s[i]='a'+shift;
        }
        return s;
    }
};