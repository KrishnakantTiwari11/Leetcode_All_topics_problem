class Solution {
public:
    string makeFancyString(string s) {
        stack<char> st;
        int c_count = 0;

        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                c_count++;
            } else {
                c_count = 1;
            }

            if (c_count < 3) {
                st.push(c);
            }
        }

        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
