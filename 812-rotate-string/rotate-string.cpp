class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal)return true;
        int n = s.length();
        if(n!=goal.length())return false;
        return(s+s).find(goal)!=-1;
    }
};