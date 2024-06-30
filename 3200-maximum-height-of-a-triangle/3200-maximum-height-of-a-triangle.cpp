class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(helper(red, blue), helper(blue, red)); // Changed math.max to max
    }
    
private:
    int helper(int red, int blue) {
        int i = 1;
        int h = 0;

        while (true) {
            if (i % 2 == 1) {
                if (red >= i) {
                    red -= i;
                } else {
                    break;
                }
            } else {
                if (blue >= i) {
                    blue -= i;
                } else {
                    break;
                }
            }
            h++;
            i++;
        }

        return h;
    }
};
