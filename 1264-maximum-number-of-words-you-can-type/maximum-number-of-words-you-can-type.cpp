class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> mp(brokenLetters.begin(), brokenLetters.end());
        int n = text.length();
        int res = 0;
        bool isValid = true;
        for (int i = 0; i < n; i++) {
            if (text[i] == ' ') {
                if (isValid == true) {
                    res++;
                }
                isValid = true;
            } else {
                if (mp.find(text[i]) != mp.end()) {
                    isValid = false;
                }
            }
        }
        if (isValid == true) {
            res++;
        }
        return res;
    }
};