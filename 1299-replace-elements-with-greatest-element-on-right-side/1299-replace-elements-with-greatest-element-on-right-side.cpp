class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
       int n=arr.size();
       for(int i=0;i<n-1;i++)
       {
           int maxvalue=0;
           for(int j=i+1;j<n;j++)
           {
               maxvalue=max(maxvalue,arr[j]);
           }
           arr[i]=maxvalue;
       }
       arr[n-1]=-1;
        return arr;
    }
};