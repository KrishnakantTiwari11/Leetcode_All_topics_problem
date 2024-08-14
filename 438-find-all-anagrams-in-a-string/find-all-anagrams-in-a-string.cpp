class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l1=p.size();
        int l2=s.size();
        if(l1>l2)
        {
            return {};
        }
        vector<int>ans;
        vector<int>vec1(26,0),vec2(26,0);
        for(int i=0;i<l1;i++)
        {
            vec1[p[i]-'a']++;
            vec2[s[i]-'a']++;
        }
        for(int i=l1;i<l2;i++){
            if(vec1==vec2)
            {
                ans.push_back(i-l1);
            }
            vec2[s[i]-'a']++;
            vec2[s[i-l1]-'a']--;
        }
       if(vec1==vec2)
       {
            ans.push_back(l2-l1);
       }
       return ans;
    }
};