class Solution {
public:
    struct vector_hash {
        size_t operator()(const vector<int>& vec) const {
            size_t hash_value = 0;
            for (int num : vec) {
                hash_value ^= hash<int>()(num) + 0x9e3779b9 +
                              (hash_value << 6) + (hash_value >> 2);
            }
            return hash_value;
        }
    };

    void sub(int i, vector<int>& temp, vector<vector<int>>& res,
             vector<int>& nums, unordered_set<vector<int>, vector_hash>& seen) {
        if (i >= nums.size()) {
            if (seen.find(temp) == seen.end()) {
                res.push_back(temp);
                seen.insert(temp);
            }
            return;
        }
        temp.push_back(nums[i]);
        sub(i + 1, temp, res, nums, seen);
        temp.pop_back();
        sub(i + 1, temp, res, nums, seen);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        unordered_set<vector<int>, vector_hash> seen;
        sort(nums.begin(), nums.end());
        sub(0, temp, res, nums, seen);
        return res;
    }
};