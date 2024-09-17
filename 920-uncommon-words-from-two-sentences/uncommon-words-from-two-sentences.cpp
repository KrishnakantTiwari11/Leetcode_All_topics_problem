class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        unordered_map<string,int>map;
        stringstream ss(s1+" "+s2);
        string word;
        while(ss>>word)
        {
            map[word]++;
        }
        for(auto ch:map)
        {
            if(ch.second==1)
            {
                ans.push_back(ch.first);
            }
        }
        return ans;
    }
};