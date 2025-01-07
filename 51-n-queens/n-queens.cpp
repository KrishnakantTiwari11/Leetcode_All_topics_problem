class Solution {
public:
    void solve(vector<vector<string>>&ans,vector<string>&temp,int n,int col,vector<int>&left_row,vector<int>& up_diag,vector<int>& l_diag){
        if(col>=n){
            ans.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++){
             if(left_row[row]==0 && l_diag[row+col]==0 && up_diag[n-1+(col-row)]==0){
                temp[row][col]='Q';
                left_row[row]=1;
                l_diag[row+col]=1;
                up_diag[n-1+(col-row)]=1;
                solve(ans,temp,n,col+1,left_row,up_diag,l_diag);
                temp[row][col]='.';
                left_row[row]=0;
                l_diag[row+col]=0;
                up_diag[n-1+(col-row)]=0;
             }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        vector<int>left_row(n);
        vector<int>up_diag(2*n-1);
        vector<int>l_diag(2*n-1);
        solve(ans,temp,n,0,left_row,up_diag,l_diag);
        return ans;
    }
};