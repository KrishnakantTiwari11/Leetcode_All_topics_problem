class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int j=0,count=0,total=0,odd=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==1)
            {
               odd++;
               if(odd>=k)
               {
                   count=1;
                  while (!(nums[j++] & 1)) count++;
                   total=total+count;
                   
               }
            }
            else if(odd>=k)
            {
                total=total+count;
            }
            
        }
        return total;
    }
};