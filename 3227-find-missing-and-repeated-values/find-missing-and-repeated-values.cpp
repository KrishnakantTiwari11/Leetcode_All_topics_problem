class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        vector<int>res(2,0);
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]]++;
            }
        }
        int j=1;
        for(int i=0;i<mp.size();i++){
            if(mp[i]==2){
                res[0]=i;
            }
            if(mp.find(j)==mp.end() && res[1]==0){
                res[1]=j;
            }
            j++;
        }
        return res;
    }
};