class Solution {
public:
    bool isSubstr(vector<int> str, vector<int> tar, string target) {
        for (int i = 0; i < 58; i++) {
            if (tar[i] > 0 && str[i] < tar[i])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int tLen = t.length(), sLen = s.length(), l = 0, minStart = 0,
            minLen = INT_MAX;
        if (t == s)
            return s;
        if (tLen > sLen)
            return "";
        string res = "";
        vector<int> sArr(58, 0);
        vector<int> tArr(58, 0);
        for (auto ch : t) {
            tArr[ch - 'A']++;
        }
        for (int r = 0; r < sLen; r++) {
            int currCharInd = s[r] - 'A';
            sArr[currCharInd]++;

            while (l <= r && isSubstr(sArr, tArr, t)) {
                int currLen = r - l + 1;
                if (currLen < minLen) {
                    minLen = currLen;
                    minStart = l;
                }
                sArr[s[l] - 'A']--;
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};