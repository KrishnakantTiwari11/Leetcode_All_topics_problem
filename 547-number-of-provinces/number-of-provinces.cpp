class Solution {
public:
    void helper(vector<vector<int>>& isConnected, vector<int>& visited, int start) {
        visited[start] = 1; // Mark the current node as visited
        for (int ch = 0; ch < isConnected.size(); ++ch) {
            if (isConnected[start][ch] == 1 && !visited[ch]) {
                helper(isConnected, visited, ch);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int res = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                res++; // Found a new connected component
                helper(isConnected, visited, i); // Explore the entire component
            }
        }
        
        return res;
    }
};
