#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        vector<int> ans;

        // Count occurrences of elements in nums1
        for (int i = 0; i < nums1.size(); i++)
            freq[nums1[i]]++;

        // Iterate through nums2 and find common elements
        for (int i = 0; i < nums2.size(); i++) {
            if (freq[nums2[i]] > 0) {
                ans.push_back(nums2[i]);
                freq[nums2[i]]--;
            }
        }

        return ans;
    }
};
