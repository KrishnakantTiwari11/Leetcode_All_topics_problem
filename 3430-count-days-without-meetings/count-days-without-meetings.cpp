class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int count=0;
        count+=meetings[0][0]-1;
        int end=meetings[0][1];
        int size=meetings.size();
        for(int i=1;i<size;i++){
            int temp=meetings[i][0]-end-1;
            if(temp>=1)count+=temp;
            end=max(end,meetings[i][1]);
        }
        count+=days-end;
        return count;
    }
};