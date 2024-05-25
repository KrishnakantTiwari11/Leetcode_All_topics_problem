class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int r=m;
        int c=n;
        for(auto o:ops)
        {
             r=min(r,o[0]);
             c=min(c,o[1]);
        }
        return r*c;      
    }
};