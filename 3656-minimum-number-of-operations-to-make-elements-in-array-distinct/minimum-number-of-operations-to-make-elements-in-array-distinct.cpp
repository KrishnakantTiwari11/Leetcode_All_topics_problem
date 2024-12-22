class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;

        while (true) {
            set<int> temp(nums.begin(), nums.end());
            if (temp.size() == nums.size()) {
                return count;
            }
            
            if (nums.size() >= 3) {
                nums.erase(nums.begin(), nums.begin() + 3);
            } else {
                nums.clear();
            }
            
            count++;
        }

        return count;
    }
};
