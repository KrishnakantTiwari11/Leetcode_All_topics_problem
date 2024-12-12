class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
         priority_queue<int> pq;

        for (int num : gifts) {
            pq.push(num);
        }

        while (k> 0) {
            int top = pq.top();
            pq.pop();
            pq.push((int)sqrt(top));
            k--;
        }

        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};