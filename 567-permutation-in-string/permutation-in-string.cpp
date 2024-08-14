class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1=s1.size();
        int l2=s2.size();
        if(l2<l1)
        {
            return false;
        }
        vector<int>vec1(26,0),vec2(26,0);
        for(int i=0;i<l1;i++)
        {
            vec1[s1[i]-'a']++;
            vec2[s2[i]-'a']++;
        }
        for(int i=l1;i<l2;i++)
        {
            if(vec1==vec2)
            {
                return true;
            }
            vec2[s2[i]-'a']++;
            vec2[s2[i-l1]-'a']--;
        }
        return vec1==vec2;
    }
};