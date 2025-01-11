class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        if(n<k)return false;
        if(n==k)return true;
        unordered_map<char,int>mp;
        int odd_count=0;
        for(auto ch:s){
            mp[ch]++;
        }
        for(auto ch:mp){
            if(ch.second%2==1){
                odd_count++;
            }
        }
        if(odd_count>k){
            return false;
        }
        return true;
    }
};