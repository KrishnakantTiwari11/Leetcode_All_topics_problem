class Solution {
public:
    bool ans=false;
    void helper(long long i, int n){
          if(i>n){
            return;
          }
          if(i==n){
            ans=true;
          }
          helper(2*i,n);
    }
    bool isPowerOfTwo(int n) {
        if(n==1){
            return true;
        }
        helper(2,n);
        return ans;
    }
};