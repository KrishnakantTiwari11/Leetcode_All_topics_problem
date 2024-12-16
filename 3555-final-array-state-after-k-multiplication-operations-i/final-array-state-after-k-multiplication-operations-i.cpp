class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int n=nums.size();
        vector<int>res(n);
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        for(int i=0;i<k;i++)
        {
            pair<int, int> temp=pq.top();
            pq.pop();
            temp.first*=multiplier;
            pq.push(temp);
        }

        for(int i=0;i<n;i++)
        {
            pair<int, int> temp=pq.top();
            pq.pop();
            res[temp.second]=temp.first;
        }
        return res;

    }
};