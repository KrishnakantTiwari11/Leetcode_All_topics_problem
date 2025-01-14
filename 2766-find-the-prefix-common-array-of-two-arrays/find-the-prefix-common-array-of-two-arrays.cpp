class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>freq(n+1,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            freq[A[i]]++;
            freq[B[i]]++;
            int count=0;
            for(int i=0;i<=n;i++){
                if(freq[i]==2)count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};