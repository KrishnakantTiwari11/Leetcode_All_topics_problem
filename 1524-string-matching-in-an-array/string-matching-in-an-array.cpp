class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        unordered_set<string>mp;
        vector<string>ans;
        for(int i=0;i<n;i++){
            string temp=words[i];
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(temp.find(words[j])!=string::npos && mp.find(words[j])==mp.end()){
                    ans.push_back(words[j]);
                    mp.insert(words[j]);
                }
            }
        }
        return ans;
    }
};