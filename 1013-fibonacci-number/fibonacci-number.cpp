class Solution {
public:
    int ans=0;
    void fibonacci(int first,int second,int sum,int n,int i){
        if(i>n){
            return;
        }
        sum=first+second;
        ans=max(ans,sum);
        i+=1;
        fibonacci(second,sum,sum,n,i);
    }
    int fib(int n) {
        if(n==1){
            return 1;
        }
        if(n==2){
            return 1;
        }
        fibonacci(0,1,0,n,2);
        return ans;
    }
};