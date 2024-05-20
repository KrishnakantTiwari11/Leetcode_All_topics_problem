class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
{
    int i = 0;
    int j = i + 1;
    vector<pair<int, int>> conclusion;
    vector<bool> result;
    while(j < nums.size())
    {
        bool cond1 = nums[i] % 2 == 0 && nums[j] % 2 != 0;
        bool cond2 = nums[i] % 2 != 0 && nums[j] % 2 == 0;
        if(!(cond1 || cond2))
            conclusion.push_back({i, j});
        i++;
        j++;
    }
    
    for(int k = 0; k < queries.size(); k++)
    {
        int start = queries[k][0];
        int end = queries[k][1];
        bool isBreaked = false;
        for(int l = 0; l < conclusion.size(); l++)
        {
            if(conclusion[l].first >= start && conclusion[l].second <= end)
            {
                result.push_back(false);
                isBreaked = true;
                break;
            }
        }
        
        if(!isBreaked) {
            result.push_back(true);
        }
        
    }
    
    return result;
}
};