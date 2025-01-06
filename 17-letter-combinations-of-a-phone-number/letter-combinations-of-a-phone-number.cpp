class Solution {
public:
    void helper(vector<string>& nums, int i, vector<string>& res, string temp) {
        if (i >= nums.size()) {
            res.push_back(temp);
            return;
        }
        string vir = nums[i];
        for (int k = 0; k < vir.size(); k++) {
            temp += vir[k];
            helper(nums, i + 1, res, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits==""){
            return {};
        }
        vector<string> letters(10);
        letters[2] = "abc";
        letters[3] = "def";
        letters[4] = "ghi";
        letters[5] = "jkl";
        letters[6] = "mno";
        letters[7] = "pqrs";
        letters[8] = "tuv";
        letters[9] = "wxyz";
        int n = digits.length();
        vector<string> nums;
        for (int i = 0; i < n; i++) {
            int digit = digits[i] - '0';
            nums.push_back(letters[digit]);
        }
        string temp;
        vector<string>res;
        helper(nums, 0,res, temp);
        return res;
    }
};