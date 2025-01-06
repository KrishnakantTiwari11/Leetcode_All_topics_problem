class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        int low = 1, high = x;
        int res;
        while (low <= high) {
            long mid = low + (high - low) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid > x)
                high = mid - 1;
            else {
                low = mid + 1;
                res = mid;
            }
        }
        return res;
    }
};