class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        int i = 0, j = 0; // Initialize both i and j to 0
        
        while (i < n1 && j < n2) {
            if (str1[i] == str2[j]) {
                i++;
                j++;
                continue;
            } else {
                char temp;
                if (str1[i] == 'z') {
                    temp = 'a';
                } else {
                    temp = str1[i] + 1;
                }
                if (temp == str2[j]) {
                    i++;
                    j++;
                    continue;
                } else {
                    i++;
                }
                
            }
        }
         if(j==n2){
                return true;
            }
        return false;
    }
};
