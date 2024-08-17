class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                char c=st.top();
                if((c=='(' && s[i]==')') || (c=='{' && s[i]=='}') || (c=='[' && s[i]==']'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
                
            }
        }
        return st.empty();
    }
};