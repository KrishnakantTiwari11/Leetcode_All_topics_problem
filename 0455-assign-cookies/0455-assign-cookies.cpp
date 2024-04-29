class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // Sort children's greed factors
        sort(s.begin(), s.end()); // Sort cookie sizes
        
        int contentChildren = 0;
        
        for (int gIndex = 0, sIndex = 0; gIndex < g.size() && sIndex < s.size(); sIndex++) {
            if (s[sIndex] >= g[gIndex]) { // If current cookie size can satisfy current child's greed factor
                contentChildren++; // Increment count of content children
                gIndex++; // Move to the next child
            }
        }
        
        return contentChildren;
    }
};
