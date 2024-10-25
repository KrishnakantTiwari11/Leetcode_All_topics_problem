class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        int n = folder.size();
        vector<string> ans;
        ans.push_back(folder[0]);
        for (int i = 1; i < n; i++) {
            string lastAdded = ans.back();
            string current = folder[i];
            if (current.find(lastAdded + "/") != 0) {
                ans.push_back(current);
            }
        }
        return ans;
    }
};