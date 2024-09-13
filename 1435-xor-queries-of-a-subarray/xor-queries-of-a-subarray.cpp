class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=queries.size();
         vector<int>ans(n,0);
         for(int i=1;i<arr.size();i++)
         {
            arr[i]=arr[i]^arr[i-1];
         }
         for(int i=0;i<n;i++)
         {
            if(queries[i][0]!=0)
            {
                ans[i]=(arr[queries[i][0]-1]^arr[queries[i][1]]);
            }
            else
            {
                ans[i]=(arr[queries[i][1]]);
            }
         }
         return ans;
    }
};