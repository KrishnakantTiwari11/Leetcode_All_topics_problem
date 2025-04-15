class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;

        queue<string> q;
        unordered_set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);
        
        int changes = 1;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string word = q.front();
                q.pop();
                if (word == endWord) return changes;

                for (int i = 0; i < word.size(); ++i) {
                    string temp = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (dict.count(temp) && !visited.count(temp)) {
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
            ++changes;
        }

        return 0;
    }
};
