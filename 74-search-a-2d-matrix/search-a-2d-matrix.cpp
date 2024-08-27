class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cs=matrix.size();
        int rs=matrix[0].size();
        int comp=0;
        for(int i=0;i<cs;i++)
        {
            if(target<=matrix[i][rs-1])
            {
                comp=i;
                break;
            }
        }
        int l=0;
        int r=rs-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(matrix[comp][mid]==target)
            {
                return true;
            }
            else if(target>matrix[comp][mid])
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return false;

    }
};