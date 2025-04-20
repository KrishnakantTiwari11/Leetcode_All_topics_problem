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
        for (auto& ch : mp) {
            int a = ch.first;
            int b = ch.second;
            while (b > 0) {
                if (a == 0) {
                    res += b;
                    break;
                } else if (a >= b) {
                    res += (a + 1);
                    break;
                } else {
                    int c = a + 1;
                    int div = b / c;
                    int rem = b % c;
                    res += div * c;
                    b = rem;
                }
            }
        }
        return res;
    }
};