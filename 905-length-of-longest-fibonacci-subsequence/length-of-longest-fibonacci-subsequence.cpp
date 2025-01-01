class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        int res=0;
        unordered_set<int>mp(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int a=arr[i],b=arr[j],l=2;
                while(mp.count(a+b)){
                    b=a+b;
                    a=b-a;
                    l++;
                }
                res=max(res,l);
            }
        }
        return res>2?res:0;
    }
};