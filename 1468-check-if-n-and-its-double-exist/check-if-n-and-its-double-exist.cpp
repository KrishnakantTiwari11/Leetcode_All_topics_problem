class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto ch:arr)
        {
            mp[ch]++;
        }
        for(int i=0;i<arr.size();i++)
        {
    
            if(mp[0]<=1 && arr[i]==0)
            {
                continue;
            }
            float j=arr[i]*2;
            if(mp.find(j)!=mp.end())
            {
                return true;
            }
        }
        return false;
    }
};