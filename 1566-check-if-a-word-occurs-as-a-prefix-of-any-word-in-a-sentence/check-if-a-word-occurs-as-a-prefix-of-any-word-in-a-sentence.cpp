class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i=0;
        int n=sentence.length()-1;
        int sw=searchWord.length();
        string temp="";
        int res=0;
        while(i<=n)
        {
            if(sentence[i]==' ')
            {
                temp="";
                res++;
                i++;
            }
                temp+=sentence[i];
                if (temp.length() == sw && temp == searchWord) {
                    return res+1;
                }
            
            i++;
            }
            return -1;
    }
};