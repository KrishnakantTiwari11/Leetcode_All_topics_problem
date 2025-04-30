class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int cells=m*n;
        vector<int>res;
        int row=0,col=0;
        visited[row][col]=1;
        res.push_back(matrix[row][col]);
        cells--;
        while(cells>=1){
            while(col<n-1 && !visited[row][col+1]){
                visited[row][col+1]=1;
                res.push_back(matrix[row][col+1]);
                col++;
                cells--;
            }
            while(row<m-1 && !visited[row+1][col]){
                visited[row+1][col]=1;
                res.push_back(matrix[row+1][col]);
                row++;
                cells--;
            }
            while(col>0 && !visited[row][col-1]){
                visited[row][col-1]=1;
                res.push_back(matrix[row][col-1]);
                col--;
                cells--;
            }
            while(row>0 && !visited[row-1][col]){
                visited[row-1][col]=1;
                res.push_back(matrix[row-1][col]);
                row--;
                cells--;
            }
        }
        return res;
    }
};