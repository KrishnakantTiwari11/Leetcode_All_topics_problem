class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int space=0;
        string res="";
        for(int i=0;i<s.length();i++)
        {
            if(space<spaces.size() && i==spaces[space])
            {
                res+=' ';
                space++;
            }
            res+=s[i];
        }
        return res;
    }
};