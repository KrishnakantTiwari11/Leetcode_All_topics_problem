class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q;
        for(int i=0;i<k;i++){
            q.push({nums[i],i});
        }
        vector<int>res;
        int n = nums.size();
        res.push_back(q.top().first);
        for(int i=k;i<n;i++){
            q.push({nums[i],i});                            
            int leftWin = i-k+1;
            while(q.top().second < leftWin){ 
                q.pop();
            }
            res.push_back(q.top().first);
        }
        return res;
    }
};