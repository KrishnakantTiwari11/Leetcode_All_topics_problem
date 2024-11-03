class Solution {
public:
    bool isBalanced(string num) {
        int odd_ind=1;
        int even_ind=0;
        int odd_val=0;
        int even_val=0;
        int n=num.length();
        while(odd_ind<n || even_ind<n)
        {
            if(even_ind<n)
            {
                 even_val +=num[even_ind]-'0';
                 even_ind +=2;
            }
            if(odd_ind<n)
            {
                odd_val +=num[odd_ind]-'0';
                odd_ind +=2;
            }
    
        }
        if(odd_val==even_val)
        {
            return true;
        }
        return false;
    }
};