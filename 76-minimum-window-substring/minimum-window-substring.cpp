class Solution {
public:
    string minWindow(string s, string t) {
        int tLen = t.length(), sLen = s.length(), l = 0, minStart = 0,
            formed = 0, required = tLen, minLen = INT_MAX;
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
            if (tArr[currCharInd] > 0 &&
                sArr[currCharInd] < tArr[currCharInd]) {
                formed++;
            }
            sArr[currCharInd]++;
            while (l <= r && formed == required) {
                int currLen = r - l + 1;
                if (currLen < minLen) {
                    minLen = currLen;
                    minStart = l;
                }
                int leftCurrInd = s[l] - 'A';
                if (tArr[leftCurrInd] > 0 &&
                    sArr[leftCurrInd] == tArr[leftCurrInd]) {
                    formed--;
                }
                sArr[s[l] - 'A']--;
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};