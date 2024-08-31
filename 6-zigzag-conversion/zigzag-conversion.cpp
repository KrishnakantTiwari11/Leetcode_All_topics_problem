class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1)
        {
            return s;
        }
        int j=0;
        int d=1;
        vector<string>temp(numRows);
        for(int i=0;i<n;i++)
        {
            temp[j]+=s[i];
            if(j==0)
            {
                d=1;
            }
            else if(j==numRows-1)
            {
                d=-1;
            }
            j=j+d;
        }
        string res="";
        for(int j=0;j<temp.size();j++)
        {
             res=res+temp[j];
        }
        return res;
    }
};