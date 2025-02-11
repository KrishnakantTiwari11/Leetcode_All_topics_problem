class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part)!=string::npos){
            int index=s.find(part);
            int n=part.length();
            s.erase(index,n);
        }
        return s;
    }
};