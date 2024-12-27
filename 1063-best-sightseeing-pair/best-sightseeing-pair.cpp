class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_i=values[0];
        int maxSum=INT_MIN;
        int n=values.size();
        for(int j=1;j<n;j++){
            maxSum=max(maxSum,max_i+values[j]-j);
            max_i=max(max_i,values[j]+j);
        }
        return maxSum;
    }
};