class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(),n=mat[0].size(),total=m*n;
        vector<vector<int>> ans(r, vector<int>(c));
        if(r*c!=total)return mat;
        for(int i=0;i<total;i++)
        {
            ans[i/c][i%c]=mat[i/n][i%n];
        }
        return ans;
    }
};