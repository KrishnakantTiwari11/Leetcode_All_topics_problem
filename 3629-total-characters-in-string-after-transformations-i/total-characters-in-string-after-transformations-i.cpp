class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        for (int i = 0; i < t; i++) {
            vector<long long> temp(26, 0);
            for (int j = 0; j < 25; j++) {
                temp[j + 1] = (temp[j + 1] + freq[j]) % MOD;
            }
            temp[0] = (freq[25]) % MOD;
            temp[1] = (temp[1] + freq[25]) % MOD;
            freq = temp;
        }
        long long res = 0;
        for (auto ch : freq) {
            res = (res + ch) % MOD;
        }
        return (int)res;
    }
};
