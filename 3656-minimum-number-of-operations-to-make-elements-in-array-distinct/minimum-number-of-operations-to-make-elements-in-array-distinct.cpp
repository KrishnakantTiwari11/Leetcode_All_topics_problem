class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int i = 0;
        int count = 0;

        while (true) {
            unordered_set<int> temp(nums.begin() + i, nums.end());
            if (temp.size() == nums.size() - i) {
                return count;
            }
            if(i+3>=nums.size()-1)
            {
                count++;
                return count;
            }
            i += 3;
            count++;
        }

        return count;
    }
};
