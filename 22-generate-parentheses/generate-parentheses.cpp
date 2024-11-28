class Solution {
public:
    void fun(int n, int open, int close, string str, vector<string>& v){
        if(open == n && close == n){
            v.push_back(str);
            return;
        }
        if(open < n){
            fun(n, open+1, close, str+"(", v);
        }
        if(close < open){
            fun(n, open, close+1, str+")", v);
        }
    }

    vector<string> generateParenthesis(int n) {
        ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        vector<string>v;
        string str = "";
        int open = 0;
        int close = 0;
        fun(n, open, close, str, v);
        return v;
    }
};