class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle the case of an empty vector
        
        int res = 1; // Initialize result to 1 as any single element is a subsequence
        int newres = 1; // Length of current increasing subsequence
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                newres++; // Increment length of current increasing subsequence
            } else {
                res = max(res, newres); // Update result
                newres = 1; // Reset length of current increasing subsequence
            }
        }
        return max(res, newres); // Return the maximum between res and newres
    }
};
