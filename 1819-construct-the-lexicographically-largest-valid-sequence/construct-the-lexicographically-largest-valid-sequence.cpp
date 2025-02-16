class Solution {
public:
    vector<int> ans;
    int flag = 0;
    void solve(vector<int>& v, int idx, int hash) {
        if (hash == 0) {

            ans = v;
            flag = 1;
            return;
        }
        if (flag == 1)
            return;
        cout << v[idx] << endl;
        if (v[idx] != 0) {
            solve(v, idx + 1, hash);
            return;
        }

        for (int i = 19; i > 0; i--) {
            if (((1 << i) & (hash))) {

                if (idx + i + 1 < v.size() && v[idx + i + 1] == 0) {
                    
                    v[idx] = i + 1;
                    v[idx + i + 1] = i + 1;

                    hash = (hash & ~(1 << (i)));
                    solve(v, idx + 1, hash);
                    hash = hash | (1 << i);
                    v[idx] = 0;
                    v[idx + i + 1] = 0;
                }
            }
        }

        if ((hash & (1))) {
            v[idx] = 1;
            hash = (hash & ~(1 << (0)));
            solve(v, idx + 1, hash);
            hash = hash | (1 << 0);
            v[idx] = 0;
        }
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> v(2 * n - 1, 0);
        int hash = 0;
        for (int i = 0; i < n; i++) {
            hash = hash | (1 << i);
        }
        solve(v, 0, hash);
        return ans;
    }
};