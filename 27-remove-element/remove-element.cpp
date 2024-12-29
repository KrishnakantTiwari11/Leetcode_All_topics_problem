class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int i=0;
        int j=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                swap(nums[i],nums[j]);
                j++;
                count++;
            }
        }
        return count;
    }
};