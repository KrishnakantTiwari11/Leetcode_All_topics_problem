class Solution {
public:
    int fibonacci(int first,int second,int n,int i){
        if(i>n){
            return second;
        }
        return fibonacci(second,first+second,n,i+1);
    }
    int fib(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        return fibonacci(0,1,n,2);

    }
};