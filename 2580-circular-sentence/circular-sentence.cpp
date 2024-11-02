class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }
        int n=words.size();
        if(n==1)
        {
            if(words[0][0]!=words[0][words[0].size()-1])
            {
                return false;
            }
        }
        if(words[0][0]!=words[n-1][words[n-1].size()-1])
            {
                return false;
            }
        for(int i=1;i<n;i++)
        {
            int f_size=words[i-1].size();
            char first=words[i-1][f_size-1];

            char sec=words[i][0];
            
            if(first!=sec)
            {
                return false;
            }
        }

        return true;
    }
};