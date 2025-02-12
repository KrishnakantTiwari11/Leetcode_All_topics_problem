class Solution {
public:
    int add(int num){
        int n=0;
        while(num>0){
            n+=num%10;
            num=num/10;
        }
        return n;
    }
    int isValid=false;
    int maximumSum(vector<int>&nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
           int temp = add(nums[i]);
           mp[temp].push_back(nums[i]);
           if(mp[temp].size()>=2)isValid=true;
        }
        if(!isValid)return -1;
        int maxSum=0;
        for(auto ch:mp){
            int fl=0;
            int sl=0;
            for(auto num:ch.second){
                if(num>fl){
                    sl=fl;
                    fl=num;
                }
                else if(num>sl){
                    sl=num;
                }
            }
            if(fl!=0 && sl!=0) maxSum=max(maxSum,fl+sl);
        }
        return maxSum;
    }

};