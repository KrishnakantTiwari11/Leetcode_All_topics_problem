class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3)
            return false;
        bool hasVowel = false, hasConsonant = false;
        unordered_map<char, bool> vowels;
        unordered_map<char, bool> consonants;
        unordered_map<char,int>numbers;
        for(char ch='0';ch<='9';ch++){
            numbers[ch]++;
        }

        // Vowels (both uppercase and lowercase)
        string vowelChars = "AEIOUaeiou";
        for (char ch : vowelChars) {
            vowels[ch] = true;
        }

        // Consonants (both uppercase and lowercase)
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            if (vowels.find(ch) == vowels.end()) {
                consonants[ch] = true;
            }
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (vowels.find(ch) == vowels.end()) {
                consonants[ch] = true;
            }
        }
        int n=word.length();
        for(int i=0;i<n;i++){

            if(vowels[word[i]]==true){
                hasVowel=true;
                continue;
            }
            else if(consonants[word[i]]==true){
                hasConsonant=true;
                continue;
            }
            else if(numbers.find(word[i])!=numbers.end()){
                continue;
            }
            else{
                return false;
            }
        }
        if(hasVowel && hasConsonant){
            return true;
        }
        return false;
    }
};