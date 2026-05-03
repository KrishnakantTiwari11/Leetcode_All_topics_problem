class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal)return true;
        int n = s.length();
        if(n!=goal.length())return false;
        for(int i=0;i<n-1;i++){
            string temp = s.substr(1);
            temp+=s[0];
            s=temp;
            if(s==goal)return true;
        }
        return false;
    }
};