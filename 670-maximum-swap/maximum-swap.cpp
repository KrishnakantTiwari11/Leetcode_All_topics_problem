#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        
        while (num > 0) {
            int digit = num % 10;
            digits.push_back(digit);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        int n = digits.size();
        
        unordered_map<int, int> last_occurrence;
        for (int i = 0; i < n; i++) {
            last_occurrence[digits[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 9; j > digits[i]; j--) {
                if (last_occurrence.find(j) != last_occurrence.end() && last_occurrence[j] > i) {
                    swap(digits[i], digits[last_occurrence[j]]);
                    
                    int reconstructed_num = 0;
                    for (int digit : digits) {
                        reconstructed_num = reconstructed_num * 10 + digit;
                    }
                    return reconstructed_num;
                }
            }
        }

        int reconstructed_num = 0;
        for (int digit : digits) {
            reconstructed_num = reconstructed_num * 10 + digit;
        }
        return reconstructed_num;
    }
};
