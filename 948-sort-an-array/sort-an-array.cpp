class Solution {
public:
    void mergeSort(vector<int>&arr,int left,int right){
        if(left>=right)return;
        int mid = left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
    void merge(vector<int>&arr,int left,int mid,int right){
        vector<int>temp;
        int l = left,r=mid+1;
        while(l<=mid && r<=right){
            if(arr[l]<arr[r]){
                temp.push_back(arr[l]);
                l++;
            }
            else{
                temp.push_back(arr[r]);
                r++;
            }
        }
        while(l<=mid){
            temp.push_back(arr[l]);
            l++;
        }
        while(r<=right){
            temp.push_back(arr[r]);
            r++;
        }
        for(int i=left;i<=right;i++){
            arr[i]=temp[i-left];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};