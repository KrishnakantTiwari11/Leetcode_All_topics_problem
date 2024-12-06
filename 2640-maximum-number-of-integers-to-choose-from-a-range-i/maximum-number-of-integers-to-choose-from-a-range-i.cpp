class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int tot_sum=0;
        int num_count=0;
        int i=1;
        unordered_map<int,int>mp;
        for(auto ch:banned)
        {
             mp[ch]++;
        }
        while(tot_sum<maxSum && i<=n)
        {
             if(mp.find(i)==mp.end() && (tot_sum+i)<=maxSum)
             {
                 num_count++;
                 tot_sum+=i;
             }
             i++;
        }
        return num_count;
    }
};