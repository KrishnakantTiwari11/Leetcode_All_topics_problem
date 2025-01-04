class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        unordered_set<char>left;
        unordered_map<char,int>right;
        unordered_set<string>seen;
        for(auto ch:s){
            right[ch]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            right[s[i]]--;
            if(right[s[i]]==0)right.erase(s[i]);
            for(auto ch:left){
                if(right.find(ch)!=right.end()){
                    string temp=string(1,ch)+s[i];
                    if(seen.find(temp)==seen.end()){
                        count++;
                        seen.insert(temp);
                    }
                }
            }
            left.insert(s[i]);
        }
        return count;
    }
};