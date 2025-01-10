class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<char>maxFreq(26,0);
        vector<string>ans;
        for(auto word2:words2){
            vector<char>freq(26,0);
            for(auto ch:word2){
                freq[ch-'a']++;
            }
            for(int i=0;i<26;i++){
                maxFreq[i]=max(maxFreq[i],freq[i]);
            }
        }
        for(auto word1:words1){
            vector<char>freq(26,0);
            for(auto ch:word1){
                freq[ch-'a']++;
            }
            bool isValid=true;
            for(int i=0;i<26;i++){
                if(freq[i]<maxFreq[i]){
                    isValid=false;
                    break;
                }
            }
            if(isValid){
                ans.push_back(word1);
            }
        }
        return ans;
    }
};