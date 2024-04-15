class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i=0;
        int carry=0;
        reverse(begin(a),end(a));
        reverse(begin(b),end(b));
        while(i<a.size() and i<b.size()){
            ans+=((a[i]!=b[i] and !carry) or (a[i]==b[i] and carry))?'1':'0';
            carry= ((a[i]=='1' and b[i]=='1') or (a[i]!=b[i] and carry));
            i++;
        }
        while(i<a.size()){
            ans+=((a[i]=='1' and carry) or (a[i]=='0' and !carry))?'0':'1';
            carry=(a[i]=='1' and carry);
            i++;
        }
         while(i<b.size()){
            ans+=((b[i]=='1' and carry) or (b[i]=='0' and !carry))?'0':'1';
            carry=(b[i]=='1' and carry);
            i++;
        }
        if(carry)ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};