class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        int pref=1;
        for(int i=0;i<n;i++)
        {
            string first=s.substr(0,pref);
            string second=s.substr(pref,n-pref);
            if(goal==second+first)
            {
                return true;
            }
            pref++;
        }
        return false;

    }
};