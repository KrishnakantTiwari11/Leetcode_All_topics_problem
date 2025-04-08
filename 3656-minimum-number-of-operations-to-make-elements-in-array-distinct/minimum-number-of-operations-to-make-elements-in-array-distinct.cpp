class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int start=0,count=0;
        while(true){
            unordered_set<int>mp;
            for(int i=start;i<n;i++){
                mp.insert(nums[i]);
            }
            if(mp.size()!=n-start){
                start+=3;
                count++;
                if(start>=n)break;
            }
            else{
                break;
            }
            
        }
        return count;
    }
};