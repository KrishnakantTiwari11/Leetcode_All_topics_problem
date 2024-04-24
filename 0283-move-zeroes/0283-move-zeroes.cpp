class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size=nums.size();
       nums.erase(remove(nums.begin(),nums.end(),0),nums.end());
        int nsize=size-nums.size();
        for(int i=0;i<nsize;i++)
        {
              nums.push_back(0);
        }
    }
};