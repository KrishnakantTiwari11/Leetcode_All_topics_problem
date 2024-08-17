class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int level=0,water=0;
        while(l<r)
        {
            if(height[l]<=height[r])
            {
                level=max(level,height[l]);
                water+=level-height[l];
                l++;
            }
            else
            {
                level=max(level,height[r]);
                water+=level-height[r];
                r--;
            }
        }
        return water;
    }
};