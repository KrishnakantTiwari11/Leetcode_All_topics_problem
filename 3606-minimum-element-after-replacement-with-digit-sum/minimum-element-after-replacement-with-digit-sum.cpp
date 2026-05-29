class Solution {
public:
    int returnSum(int num){
        int sum =0;
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for(auto ch:nums){
            res= min(res,returnSum(ch));
        }
        return res;
    }
};