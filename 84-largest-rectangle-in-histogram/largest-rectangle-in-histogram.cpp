class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int start = i;
            while (!st.empty() && st.top().second > heights[i]) {
                int width = i - st.top().first;
                int height = st.top().second;
                start = st.top().first;
                res = max(res, (width * height));
                st.pop();
            }
            st.push({start, heights[i]});
        }
        while (!st.empty()) {
            int width = n - st.top().first;
            int height = st.top().second;
            res = max(res, (width * height));
            st.pop();
        }
        return res;
    }
};