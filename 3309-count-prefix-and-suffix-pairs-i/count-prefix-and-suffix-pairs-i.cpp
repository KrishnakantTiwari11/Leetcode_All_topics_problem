class Solution {
public:
    bool isboth(string str1,string str2){
        int l1=str1.length();
        int l2=str2.length();
        if(l2<l1){
            return false;
        }
        if(str1!=str2.substr(0,l1))return false;
        int l_ind=l2-l1;
        if(str1!=str2.substr(l_ind,l1))return false;
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               if(isboth(words[i],words[j]))count++;
            }
        }
        return count;
    }
};