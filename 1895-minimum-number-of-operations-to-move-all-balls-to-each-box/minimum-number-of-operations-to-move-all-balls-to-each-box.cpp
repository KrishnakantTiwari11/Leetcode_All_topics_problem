class Solution {
public:
    vector<int> minOperations(string boxes) {
        string s=boxes;
        int n=boxes.length();
        vector<int>left(n,0);
        vector<int>right(n,0);
        int one_count=0;
        for(int i=0;i<n;i++){
            if(i>0){
                left[i]+=left[i-1]+one_count;
            }
            if(s[i]=='1'){
                one_count++;
            }
        }
        one_count=0;
        for(int i=n-1;i>=0;i--){
            if(i<n-1){
                right[i]+=right[i+1]+one_count;
            }
             if(s[i]=='1'){
                one_count++;
             }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=left[i]+right[i];
        }
        return ans;
    }
};