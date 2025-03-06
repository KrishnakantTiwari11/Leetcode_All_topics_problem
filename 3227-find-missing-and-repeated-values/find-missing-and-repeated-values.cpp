class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int size = grid.size() * grid[0].size();
        vector<int> freq(size + 1, 0), res(2, 0);
        
        for (const auto& row : grid) {
            for (int num : row) {
                freq[num]++;
            }
        }
        
        for (int i = 1; i <= size; i++) {
            if (freq[i] == 2) res[0] = i;  
            if (freq[i] == 0) res[1] = i; 
        }
        
        return res;
    }
};
