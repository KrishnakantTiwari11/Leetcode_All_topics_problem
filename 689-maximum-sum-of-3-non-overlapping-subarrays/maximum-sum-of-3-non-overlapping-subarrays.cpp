class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>sum(n-k+1);
        vector<int>left(n-k+1);
        vector<int>right(n-k+1);
        int curr_sum=0;
        for(int i=0;i<n;i++){
            curr_sum+=nums[i];
            if(i>=k-1){
               sum[i-k+1]=curr_sum;
               curr_sum-=nums[i-k+1];
            }
        }
        int best=0;
        for(int i=0;i<sum.size();i++){
            if(sum[i]>sum[best]){
                best=i;
            }
            left[i]=best;
        }
        best=sum.size()-1;
        for(int i=sum.size()-1;i>=0;i--){
            if(sum[i]>=sum[best]){
                best=i;
            }
            right[i]=best;
        }
        int maxSum=INT_MIN;
        vector<int>res(3,0);
        for(int i=k;i<sum.size()-k;i++){
            int num=sum[i];
            int l_ind=left[i-k];
            int r_ind=right[i+k];
            int tot_sum=sum[l_ind]+sum[r_ind]+num;
            if(tot_sum>maxSum){
                maxSum=tot_sum;
                res={l_ind,i,r_ind};
            }
        }
        return res;
        
    }
};