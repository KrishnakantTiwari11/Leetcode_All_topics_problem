class Solution {
public:
    int minimumLength(string s) {
        int length=0;
        vector<int>freq(26,0);
        for(auto ch:s){
            freq[ch-'a']++;
        }
        for(auto num:freq){
            if(num==0)continue;
            if(num%2==0){
                length+=2;
            }
            else{
                length+=1;
            }
        }
        return length;
    }
};