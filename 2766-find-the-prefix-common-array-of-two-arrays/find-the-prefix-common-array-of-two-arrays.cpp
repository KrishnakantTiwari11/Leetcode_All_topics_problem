class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>freq(55,0);
        int n=A.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            freq[A[i]]++;
            freq[B[i]]++;
            int count=0;
            for(int i=0;i<55;i++){
                if(freq[i]==2)count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};