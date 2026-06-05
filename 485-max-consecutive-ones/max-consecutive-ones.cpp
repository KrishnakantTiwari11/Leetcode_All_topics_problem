class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 1, n = nums.size(), tempCount = 1;
        bool oneOneExists=nums[0]==1;
        for (int i = 1; i < n; i++) {
            if(nums[i]==1){
                oneOneExists=true;
            }
            if (nums[i] == 1 && nums[i] == nums[i - 1]) {
                tempCount++;
            } else {
                res = max(res, tempCount);
                tempCount = 1;
            }
        }
        if(!oneOneExists)return 0;
        return max(res,tempCount);
    }
};