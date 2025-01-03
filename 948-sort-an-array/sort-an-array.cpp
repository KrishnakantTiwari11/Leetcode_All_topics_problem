class Solution {
public:
    void qs(vector<int>&arr,int low,int high){
        if(low<high){
            int pivot_index=pivot(arr,low,high);
            qs(arr,low,pivot_index-1);
            qs(arr,pivot_index+1,high);
        }
    }
    int pivot(vector<int>&arr,int low,int high){
            int i=low,j=high;
            int p_value=arr[low];
            while(i<j){
            while(arr[i]<=p_value && i<=high-1){
                i++;
            }
            while(arr[j]>p_value && j>=low+1){
                j--;
            }
            if(i<j){
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[low],arr[j]);
        return j;
    }

    vector<int> sortArray(vector<int>& nums) {
        qs(nums,0,nums.size()-1);
        return nums;
    }
};