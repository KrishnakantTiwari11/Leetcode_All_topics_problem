class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int j=n-1;
        int count=0;
        for(int i=0;i<n;i++){
            while(j>i && nums[j]==val){
                j--;
            }
            if(i<j && nums[i]==val){
                swap(nums[i],nums[j]);
                j--;
            }
            if(nums[i]!=val){
                count++;
            }
        }
        return count;
    }
};