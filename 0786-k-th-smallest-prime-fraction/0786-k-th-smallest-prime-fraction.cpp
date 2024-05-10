class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<vector<double>> ans;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans.push_back(
                    {arr[i] * 1.0 / arr[j] * 1.0, arr[i] * 1.0, arr[j] * 1.0});
            }
        }
        k=k-1;
        sort(ans.begin(),ans.end());
        int first=ans[k][1];
        int sec=ans[k][2];
        return{first,sec};
    }
};