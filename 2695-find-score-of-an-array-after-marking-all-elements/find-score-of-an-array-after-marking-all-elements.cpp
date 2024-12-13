class Solution {
public:
      struct Compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a > b; 
    }
};


    long long findScore(vector<int>& nums) {
         priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
         set<int>marked;
         int n=nums.size();
         long long score=0;
         for(int i=0;i<n;i++)
         {
            pq.push({nums[i],i});
         }

         while(!pq.empty())
         {
                pair<int, int> top = pq.top();
                pq.pop();
                if(!marked.empty() &&  marked.find(top.second)!=marked.end())
                {
                    continue;
                }
                score+=top.first;
                if(top.second==0)
                {
                    marked.insert(1);
                }
                else if(top.second==n-1)
                {
                    marked.insert(n-2);
                }
                else
                {
                    marked.insert(top.second-1);
                    marked.insert(top.second+1);
                }
         }
         return score;
    }
};