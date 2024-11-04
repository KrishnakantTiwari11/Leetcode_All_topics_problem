class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        int count = 1;
        string comp = "";
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == word[i - 1]) {
                count++;
                if (count == 9) {
                    count = 0;
                    comp += "9";
                    comp += word[i - 1];
                }
            } else {
                if (count > 0) {
                    comp += to_string(count);
                    comp += word[i - 1];
                }
                count = 1;
            }
        }
        if (count > 0) {
            comp += to_string(count);
            comp += word[n - 1];
        }
        return comp;
    }
};