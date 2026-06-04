class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> temp;
        int extraElement = 0, k;
        unordered_set<int> st;
        for (auto num : nums) {
            if (st.find(num) == st.end()) {
                temp.push_back(num);
                st.insert(num);
            } else {
                extraElement++;
            }
        }
        k = temp.size();
        int diff = nums.size() - k;
        for (int i = 0; i < diff; i++) {
            temp.push_back(0);
        }
        nums = temp;
        return k;
    }
};