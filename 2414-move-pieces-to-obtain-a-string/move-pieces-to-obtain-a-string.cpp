class Solution {
public:
    bool canChange(string start, string target) {
        string s1, t1;
        for (char c : start) if (c != '_') s1 += c;
        for (char c : target) if (c != '_') t1 += c;
        if (s1 != t1) return false;

        int n = start.size();
        int p1 = 0, p2 = 0;
        while (p1 < n && p2 < n) {
            while (p1 < n && start[p1] == '_') p1++;
            while (p2 < n && target[p2] == '_') p2++;

            if (p1 == n && p2 == n) return true;
            if ((p1 == n || p2 == n) || start[p1] != target[p2]) return false;

            if (start[p1] == 'L' && p1 < p2) return false;
            if (start[p1] == 'R' && p1 > p2) return false;

            p1++;
            p2++;
        }
        return true;
    }
};