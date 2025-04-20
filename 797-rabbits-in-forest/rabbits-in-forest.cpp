class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        int res = 0;
        int num = 0;
        for (auto ch : answers) {
            mp[ch]++;
            if (ch == 0)
                num++;
        }
        for (auto &ch : mp) {
            int a = ch.first;
            int b = ch.second;
            while (ch.second > 0) {
                if (ch.first == 0) {
                    res += ch.second;
                    break;
                } else if (ch.first >= ch.second) {
                    res += (ch.first + 1);
                    break;
                } else if (ch.first + 1 == ch.second) {
                    res += ch.second;
                    break;
                } else {
                    int c = ch.first + 1;
                    int div = ch.second/c;
                    int rem =ch.second%c;
                    res += div * c;
                    ch.second = rem;
                }
            }
        }
        return res;
    }
};