class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char>mp{'a','e','i','o','u'};
        int q_size=queries.size();
        vector<int>res;
        int n=words.size();
        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i];
            if(mp.count(words[i].front()) && mp.count(words[i].back())){
                prefix[i+1]++;
            }
        }
        for(auto ch:queries){
            int L=ch[0],R=ch[1];
            res.push_back(prefix[R+1]-prefix[L]);
        }
        return res;
    }
};