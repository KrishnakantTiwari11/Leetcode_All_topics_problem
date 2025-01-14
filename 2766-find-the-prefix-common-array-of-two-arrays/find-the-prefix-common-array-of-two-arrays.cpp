class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>a(55,0);
        vector<int>b(55,0);
        int n=A.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            a[A[i]]++;
            b[B[i]]++;
            int count=0;
            for(int i=0;i<55;i++){
                if(a[i]==0 || b[i]==0)continue;
                if(a[i]==b[i])count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};