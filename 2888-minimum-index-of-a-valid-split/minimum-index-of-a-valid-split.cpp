class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int maxnum;
        int freq=0;
        unordered_map<int,int>mp;
        for(auto ch:nums){
             mp[ch]++;
             if(mp[ch]>freq){
                freq=mp[ch];
                maxnum=ch;
             }
        }
        int n=nums.size();
        int l=0;
        int r=freq;
        for(int i=0;i<n;i++){
            if(nums[i]==maxnum){
               l++;
               r--;
               int l_sub=i+1;
               int r_sub=n-1-i;
               if(l*2>l_sub && r*2>r_sub){
                   return i;
               }
            }
        }
         return -1;
    }
};