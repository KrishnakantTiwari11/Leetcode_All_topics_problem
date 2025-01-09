class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        int l2=pref.length();
        for(auto word:words){
            if(word.substr(0,l2)==pref)count++;
        }
        return count;
    }
};