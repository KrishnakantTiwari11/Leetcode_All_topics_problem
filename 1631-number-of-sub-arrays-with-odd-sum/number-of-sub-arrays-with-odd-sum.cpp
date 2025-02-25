class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oddCount = 0, prefixSum=0;
        for (int i = 0; i < arr.size(); i++) {
            prefixSum+=arr[i];
            oddCount+=prefixSum%2;
        }
        oddCount += (arr.size() - oddCount) * oddCount;
        return oddCount % 1000000007;
    }
};