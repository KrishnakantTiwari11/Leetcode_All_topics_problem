class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int>Nums;
        int n=nums.size();
        if(n==0)return 0;
        Nums.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])continue;
            Nums.push_back(nums[i]);
        }
        n=Nums.size();
        int hills=0,valleys=0;
        for(int i=1;i<n-1;i++){
            if(Nums[i]<Nums[i+1] && Nums[i]<Nums[i-1])valleys++;
            if(Nums[i]>Nums[i+1] && Nums[i]>Nums[i-1])hills++;
        }
        return hills+valleys;
    }
};