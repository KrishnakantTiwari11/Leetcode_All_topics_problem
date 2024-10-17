

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;

        // Split the number into its digits
        while (num > 0) {
            int digit = num % 10;
            digits.push_back(digit);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());

        int n = digits.size();
        // Create an array to store the last occurrence of each digit
        unordered_map<int, int> last_occurrence;
        for (int i = 0; i < n; ++i) {
            last_occurrence[digits[i]] = i; // Store the last index of each digit
        }

        // Try to find the maximum digit to swap with
        for (int i = 0; i < n; ++i) {
            // Check digits from 9 to digits[i] + 1
            for (int d = 9; d > digits[i]; --d) {
                if (last_occurrence.find(d) != last_occurrence.end() && last_occurrence[d] > i) {
                    // Swap and return the result
                    swap(digits[i], digits[last_occurrence[d]]);
                    // Reconstruct the number
                    int reconstructed_num = 0;
                    for (int digit : digits) {
                        reconstructed_num = reconstructed_num * 10 + digit;
                    }
                    return reconstructed_num; // Return immediately after the first swap
                }
            }
        }

        // If no swap is made, return the original number
        int reconstructed_num = 0;
        for (int digit : digits) {
            reconstructed_num = reconstructed_num * 10 + digit;
        }
        return reconstructed_num;
    }
};


