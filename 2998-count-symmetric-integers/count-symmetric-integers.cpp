class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res=0;
        for(int i=low;i<=high;i++){
            string temp=to_string(i);
            if(temp.size()%2==0){
                int even_size=temp.size()/2;
                int left_side=0;
                int right_side=0;
                for(int j=0;j<even_size;j++){
                    left_side+=temp[j]-'0';
                }
                for(int j=even_size;j<temp.size();j++){
                    right_side+=temp[j]-'0';
                }
                if(left_side==right_side)res++;
            }
        }
        return res;
    }
};