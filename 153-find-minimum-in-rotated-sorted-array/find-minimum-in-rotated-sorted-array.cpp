class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        
        if(n == 1) {
            return nums[0];
        }
        
        while(low <= high) {
            if(nums[low] <= nums[high]) return nums[low];
            
            int mid = low + (high - low) / 2;
            
            if(mid > 0 && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }
            if(mid < n - 1 && nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            
            if(nums[mid] >= nums[low]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return -1;
    }
};