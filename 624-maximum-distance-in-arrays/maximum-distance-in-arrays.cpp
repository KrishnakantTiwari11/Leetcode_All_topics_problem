class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_num=INT_MAX;
        int max_num=INT_MIN;
        int no_visit;
        int size=arrays.size();
        for(int i=0;i<size;i++)
        {
            if(arrays[i][0]<min_num)
            {
                min_num=arrays[i][0];
                no_visit=i;
            }
        }
        for(int i=0;i<size;i++)
        {
            if(i!=no_visit)
            {
                max_num=max(max_num,arrays[i][arrays[i].size()-1]);
            }
        }
        int max_num1=INT_MIN;
        int min_num1=INT_MAX;
        int no_visit1;
        for(int i=0;i<size;i++)
        {
            if(arrays[i][arrays[i].size()-1]>max_num1)
            {
                max_num1=arrays[i][arrays[i].size()-1];
                no_visit1=i;
            }
        }
        for(int i=0;i<size;i++)
        {
            if(i!=no_visit1)
            {
                min_num1=min(min_num1,arrays[i][0]);
            }
        }

        return max(max_num-min_num,max_num1-min_num1);
    }
};