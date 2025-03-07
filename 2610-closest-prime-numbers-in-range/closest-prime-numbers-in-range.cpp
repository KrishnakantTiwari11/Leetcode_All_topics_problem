class Solution {
public:
    bool isPrime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime_nums;
        for (int i = left; i <=right; i++) {
            if (isPrime(i)) {
                prime_nums.push_back(i);
            }
        }
        int mini=INT_MAX;
        int f=-1,s=-1;
        for(int i=1;i<prime_nums.size();i++){
             if(prime_nums[i]-prime_nums[i-1]<mini){
                mini=prime_nums[i]-prime_nums[i-1];
                f=prime_nums[i];
                s=prime_nums[i-1];
             }
        }
        return {s,f};
    }
};