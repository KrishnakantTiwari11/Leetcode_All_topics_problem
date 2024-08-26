class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size=matrix[0].size();
        int col_size=matrix.size();
        for(int i=0;i<col_size;i++)
        {
            int l=0;
            int r=row_size-1;
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(matrix[i][mid]==target)
                {
                    return true;
                }
                else if(target>matrix[i][mid])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        return false;
    }
};