class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        if (numRows == 1)
            return res;
        for (int i = 2; i <= numRows; i++) {
            vector<int> curr = res.back();
            int n = curr.size();
            vector<int> temp;
            temp.push_back(curr.front());
            for (int j = 1; j < n; j++) {
                temp.push_back(curr[j] + curr[j - 1]);
            }
            temp.push_back(curr.back());
            res.push_back(temp);
        }
        return res;
    }
};