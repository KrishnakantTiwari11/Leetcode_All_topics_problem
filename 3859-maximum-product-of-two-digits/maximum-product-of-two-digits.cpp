class Solution {
public:
    int maxProduct(int n) {
        int fl=INT_MIN,sl=INT_MIN;
        while(n>0){
            int temp=n%10;
            if(temp>=fl){
                sl=fl;
                fl=temp;
            }
            else if(temp>sl){
                sl=temp;
            }
            n=n/10;
        }
        return sl*fl;
    }
};