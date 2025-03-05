class Solution {
public:
    long long coloredCells(int n) {
        if(n==1)return 1;
        long long val=1;
        long long init=4;
        for(int i=2;i<=n;i++){
             val+=init;
             init=4*i;
        }
        return val;
    }
};