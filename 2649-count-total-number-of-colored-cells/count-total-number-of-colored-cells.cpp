class Solution {
public:
    long long coloredCells(int n) {
        long long init=0;
        for(int i=0;i<n;i++){
           init+=i;
        }
        return init*4+1;
    }
};