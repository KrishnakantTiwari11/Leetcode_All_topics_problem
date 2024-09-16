class Solution {
public:
void tominutes(int i,vector<string>&timepoints,vector<int>&minutes)
        {
           int h=stoi(timepoints[i].substr(0,2));
           int m=stoi(timepoints[i].substr(3));
           minutes[i]=h*60+m;
        }
    int findMinDifference(vector<string>& timePoints) {
        int minans=INT_MAX,n=timePoints.size();
        vector<int>minutes(n,0);
        for(int i=0;i<n;i++)
        {
           tominutes(i,timePoints,minutes);
        }
        sort(minutes.begin(),minutes.end());
        for(int i=0;i<n-1;i++)
        {
            minans=min(minans,minutes[i+1]-minutes[i]);
        }
        minans=min(minans,24*60-(minutes.back()-minutes.front()));
        return minans;
        
    }
};