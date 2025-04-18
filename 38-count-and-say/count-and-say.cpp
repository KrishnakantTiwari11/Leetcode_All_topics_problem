class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        n--;
        string temp="1";
        int num_count=1;
        while(n--){
            string res="";
            for(int i=0;i<temp.size();i++){
                if(i+1<temp.size()){
                    if(temp[i]==temp[i+1]){
                        num_count++;
                    }
                    else{
                        string add=to_string(num_count)+(temp[i]);
                        res+=add;
                        num_count=1;
                    }
                }
                else{
                    string add=to_string(num_count)+temp[i];
                    res+=add;
                    num_count=1;
                }
            }
            temp=res;
        }
        return temp;
    }
};