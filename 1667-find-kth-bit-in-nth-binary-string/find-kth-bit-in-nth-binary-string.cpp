class Solution {
public:
    string invert(string bin_num) {
        for (int i = 0; i < bin_num.length(); i++) {
            if (bin_num[i] == '0') {
                bin_num[i] = '1';
            } else {
                bin_num[i] = '0';
            }
        }
        return bin_num;
    }

    string reverse(string bin_num) {
        int l = 0;
        int r = bin_num.length()-1;
        while (l < r) {
            swap(bin_num[l], bin_num[r]);
            l++;
            r--;
        }
        return bin_num;
    }
    char findKthBit(int n, int k) {
        // if(n==1 && k==1)
        // {
        //     return '0';
        // }
        string str = "0";
        string fin = "";
        n=n-1;
        k=k-1;
        for (int i = 0; i < n; i++) {
            fin = str + "1" + reverse(invert(str));
            str = fin;
        }
        return str[k];
    }
};