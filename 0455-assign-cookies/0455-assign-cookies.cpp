class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); 
        sort(s.begin(), s.end()); 
        
        int contentChildren = 0;
        
       for(int gi=0,si=0;gi<g.size() && si<s.size();si++)
       {
           if(s[si]>=g[gi])
           {
               contentChildren++;
               gi++;
           }
       }
        
        return contentChildren;
    }
};
