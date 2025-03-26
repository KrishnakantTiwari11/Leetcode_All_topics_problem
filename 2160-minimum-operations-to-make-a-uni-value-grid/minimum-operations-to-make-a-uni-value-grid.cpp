class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>temp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                temp.push_back(grid[i][j]);
            }
        }
        sort(temp.begin(),temp.end());
        int n=temp.size();
        int med=temp[n/2];
        int res=0;
        for(auto ch:temp){
            int curr=abs(ch-med);
            if(curr%x==0){
                 res+=curr/x;
            }
            else{
                return -1;
            }
        }
        return res;
    }
};