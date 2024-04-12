class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        digits[n]++; // Add 1 to the last digit
        
        // Carry propagation
        for (int i = n; i > 0 && digits[i] == 10; i--) {
            digits[i] = 0; // Set the current digit to 0
            digits[i - 1]++; // Increment the next higher-order digit
        }
        
        // If the first digit also becomes 10, insert 1 at the beginning
        if (digits[0] == 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
