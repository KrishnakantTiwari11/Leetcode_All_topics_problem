#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        int ptr = nums[0];
        vector<string> res;
        for(int i = 1; i < n; i++) {
            if (nums[i - 1] != nums[i] - 1) {
                if (ptr == nums[i - 1]) {
                    res.push_back(to_string(ptr));
                } else {
                    res.push_back(to_string(ptr) + "->" + to_string(nums[i - 1]));
                }
                ptr = nums[i];
            }
        }
        
        if (ptr == nums[n - 1]) {
            res.push_back(to_string(ptr));
        } else {
            res.push_back(to_string(ptr) + "->" + to_string(nums[n - 1]));
        }
        
        return res;
    }
};

