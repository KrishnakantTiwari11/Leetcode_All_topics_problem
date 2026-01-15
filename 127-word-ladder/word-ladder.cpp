class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            string currWord = q.front().first;
            int currLevel = q.front().second;
            if(currWord==endWord)return currLevel;
            q.pop();
            for (int i = 0; i < currWord.size(); i++) {
                char original = currWord[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == original)
                        continue;
                    currWord[i] = ch;
                    if (st.count(currWord)) {
                        q.push({currWord, currLevel + 1});
                        st.erase(currWord);
                    }
                }
                currWord[i] = original;
            }
        }
        return 0;
    }
};