#include <string>
#include <vector>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2) {
            return false;
        }

        std::vector<int> s1Freq(26, 0), s2Freq(26, 0);

        for (int i = 0; i < len1; ++i) {
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }

        for (int i = len1; i < len2; ++i) {
            if (s1Freq == s2Freq) {
                return true;
            }
            s2Freq[s2[i] - 'a']++;
            s2Freq[s2[i - len1] - 'a']--;
        }

        return s1Freq == s2Freq;
    }
};
