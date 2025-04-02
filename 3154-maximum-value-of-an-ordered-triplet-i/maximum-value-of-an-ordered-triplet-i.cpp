class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res=0;
        vector<int>prefix(n,-1);
        vector<int>suffix(n,-1);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],nums[i]);
        }
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],nums[i]);
        }
        for(int i=1;i<n-1;i++){
            long long temp=(long long)(prefix[i-1]-nums[i])*suffix[i+1];
            res=max(res,temp);
        }
        return res;

    }
};
