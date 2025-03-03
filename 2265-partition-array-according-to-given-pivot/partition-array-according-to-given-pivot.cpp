class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>arr1;
        vector<int>arr2;
        int n=0;
        for(auto ch:nums){
            if(ch==pivot)n++;
            if(ch<pivot)arr1.push_back(ch);
            if(ch>pivot)arr2.push_back(ch);
        }
        for(int i=0;i<n;i++){
            arr1.push_back(pivot);
        }
        for(int i=0;i<arr2.size();i++){
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};