class Solution {
public:
    bool isSafe(int row,int col,int n,vector<string>&temp){
          int duprow=row;
          int dupcol=col;
          //upper diagonal
          while(row>=0 && col>=0){
            if(temp[row][col]=='Q')return false;
            row--;
            col--;
          }
          row=duprow;
          col=dupcol;
          //left col
          while(col>=0){
            if(temp[row][col]=='Q')return false;
            col--;
          }
          row=duprow;
          col=dupcol;
          while(row<n && col>=0){
            if(temp[row][col]=='Q')return false;
            row++;
            col--;
          }
          return true;
    }
    void solve(vector<vector<string>>&ans,vector<string>&temp,int n,int col){
        if(col>=n){
            ans.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++){
             if(isSafe(row,col,n,temp)){
                temp[row][col]='Q';
                solve(ans,temp,n,col+1);
                temp[row][col]='.';
             }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        solve(ans,temp,n,0);
        return ans;
    }
};