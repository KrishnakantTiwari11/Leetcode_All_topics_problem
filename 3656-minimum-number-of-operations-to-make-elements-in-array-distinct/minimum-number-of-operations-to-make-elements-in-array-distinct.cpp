class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int i = 0;
        int count = 0;
        map<int, int> temp;
        
        for (int num : nums) {
            temp[num]++;
        }

        while (true) {
            if (temp.size() == nums.size() - i) {
                return count;
            }
            if(i + 3 >= nums.size() - 1) {
                count++;
                return count;
            }
            
            temp[nums[i]]--;
            if (temp[nums[i]] == 0) temp.erase(nums[i]);
            
            temp[nums[i+1]]--;
            if (temp[nums[i+1]] == 0) temp.erase(nums[i+1]);
            
            temp[nums[i+2]]--;
            if (temp[nums[i+2]] == 0) temp.erase(nums[i+2]);

            i += 3;
            count++;
        }

        return count;
    }
};
