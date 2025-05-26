class Solution {
public:
    long long cost(int num,int k){
        long long res=0;
        long long pieces = num - k;
        res = k*pieces;
        return res;

    }
    long long minCuttingCost(int n, int m, int k) {
        if(m<=k && n<=k)return 0;
        long long a=0,b=0;
        if(n>k){
            a=cost(n,k);
        }
        if(m>k){
            b=cost(m,k);
        }
        return a+b;
    }
};