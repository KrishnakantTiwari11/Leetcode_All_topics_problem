#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> ans;
        std::deque<int> dq; // This will store indices of elements in the window

        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices of elements not in the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove elements from the back of the deque if they are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add the current element's index to the back of the deque
            dq.push_back(i);

            // The maximum of the current window is at the front of the deque
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};

