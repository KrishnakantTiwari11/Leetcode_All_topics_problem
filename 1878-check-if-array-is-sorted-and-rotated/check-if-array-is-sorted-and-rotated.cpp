class Solution {
public:
    bool check(vector<int>& nums) {
        int diff = 0, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                diff++;
            }
            if (diff == 2)
                return false;
            if (diff == 1 && nums[i] > nums[0])
                return false;
        }
        return true;
    }
};