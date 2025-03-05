class Solution {
public:
    long long coloredCells(int n) {
        long long temp = n;
        return 1 + 2 * (temp - 1) * (temp);
    }
};