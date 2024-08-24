class Solution {
public:
    vector<int> prevSmallerElement(vector<int>& heights,int n){
    stack<int> s;
    vector<int> prevSmaller(n);
    for(int i=0;i<n;i++){
        while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
        prevSmaller[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return prevSmaller;
}

vector<int> nextSmallerElement(vector<int>& heights,int n){
    stack<int> s;
    vector<int> nextSmaller(n);
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
        nextSmaller[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    return nextSmaller;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> nextSmaller = nextSmallerElement(heights,n);
    vector<int> prevSmaller = prevSmallerElement(heights,n);        
    int maxArea = 0;
    for(int i=0;i<n;i++){
        int area = (nextSmaller[i]-prevSmaller[i]-1)*heights[i];
        maxArea = max(area,maxArea);
    }
    return maxArea;
}
};