class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> mat(n);
        queue<int> q;
        vector<int> inDegree(n, 0), res;
        
        //Converting pair into adjacency list
        for (auto pre : prerequisites) {
            int u = pre[0];
            int v = pre[1];
            mat[v].push_back(u);
        }

        //Calculating InDegree for each node
        for (auto ch : mat) {
            for (int i = 0; i < ch.size(); i++) {
                inDegree[ch[i]]++;
            }
        }

        //Pushing node with InDegree==0 in the queue
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for (auto ch : mat[curr]) {
                inDegree[ch]--;
                if (inDegree[ch] == 0) {
                    q.push(ch);
                }
            }
        }
        if (res.size() == n)
            return res;
        return {};
    }
};