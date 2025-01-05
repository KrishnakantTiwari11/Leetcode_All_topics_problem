class Solution {
public:
    long long calculateScore(string s) {
        long long res = 0;
        int n = s.length();
        unordered_map<char, priority_queue<int>> mp;
        unordered_map<char, char> mirror;

        char start = 'z', end = 'a';
        while (start >= end) {
            mirror[start] = end;
            mirror[end] = start;
            start--;
            end++;
        }

        for (int i = 0; i < n; i++) {
            char current = s[i];
            char key = mirror[current];

            if (mp.find(key) != mp.end() && !mp[key].empty()) {
                int j_ind = mp[key].top();
                mp[key].pop();
                res += (i - j_ind);
            }
            else{
                mp[current].push(i);
            }
        }

        return res;
    }
};