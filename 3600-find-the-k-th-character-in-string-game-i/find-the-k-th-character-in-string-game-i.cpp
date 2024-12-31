class Solution {
public:
    char kthCharacter(int k) {
        string res="a";
        while(true){
            if(res.length()>=k){
                return res[k-1];
            }
            string temp="";
            for(int i=0;i<res.length();i++){
                if(res[i]=='z'){
                    temp+='a';
                }
                else{
                    temp+=res[i]+1;
                }
            }
            res+=temp;
        }
        return 'a';
    }
};