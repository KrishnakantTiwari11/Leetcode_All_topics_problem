class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>res;
        int n=nums.size();
        int w_size=0;
        bool inserted=false;
        int max_num=INT_MIN;
        for(int i=0;i<=n-k;i++)
        {
            inserted=false;
            w_size=i;
            max_num=INT_MIN;
            while(w_size<i+k-1)
            {
                if(nums[w_size]+1!=nums[w_size+1])
                {
                    res.push_back(-1);
                    inserted=true;
                    break;
                }
                w_size++;
            }
            if(!inserted)
            {
                res.push_back(nums[i+k-1]);
            }
        }
        return res;
    }
};