class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        vector<int> vec1(26, 0);

        for (char ch : allowed) {
            vec1[ch - 'a'] = 1;
        }

        for (const string& word : words) {
            bool isConsistent = true;
            for (char ch : word) {
                if (vec1[ch - 'a'] == 0) {
                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent) {
                count++;
            }
        }
        
        return count;
    }
};
