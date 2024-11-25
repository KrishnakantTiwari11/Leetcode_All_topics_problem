class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minimum=INT_MAX;
        int n=matrix.size();
        long long sum=0;
        int negative_count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               sum+=abs(matrix[i][j]);
               minimum=min(minimum,abs(matrix[i][j]));
               if(matrix[i][j]<0)
               {
                negative_count++;
               }
            }
        }
        if(negative_count%2!=0)
        {
            return sum-(2*minimum);
        }
        return sum;
    }
};