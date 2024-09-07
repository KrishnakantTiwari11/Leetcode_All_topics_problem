class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;
        for(auto ch:s)
        {
            map1[ch]++;
        }
        for(auto ch:t)
        {
            map2[ch]++;
        }
        if(map1==map2)
        {
            return true;
        }
        return false;

    }
};