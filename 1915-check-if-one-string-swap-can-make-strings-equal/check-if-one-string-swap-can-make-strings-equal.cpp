class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return true;
        vector<int>arr1(26,0);
        vector<int>arr2(26,0);
        int n=s1.length();
        for(int i=0;i<n;i++){
            arr1[s1[i]-'a']++;
            arr2[s2[i]-'a']++;
        }
        int count=0;
        if(arr1==arr2){
            for(int i=0;i<n;i++){
                if(s1[i]!=s2[i])count++;
            }
        }
        else{
            return false;
        }
        if(count<=2)return true;
        return false;
    }
};