class NumArray {
public:
    vector<int>nums1;
    NumArray(vector<int>& nums) {
        this->nums1=nums;
    }
    
    int sumRange(int left, int right) {
        long long ans=0;
        for(int i=left;i<=right;i++)
        {
            ans=ans+nums1[i];
        }
        return ans;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */