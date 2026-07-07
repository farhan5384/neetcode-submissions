class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int x, y;

        priority_queue<int> pq;
        for (auto& p : stones) {
            pq.push(p);
        }

        while (!pq.empty() && pq.size() > 1) {
            x = pq.top();

            pq.pop();
            if (!pq.empty()) {
                y = pq.top();
                pq.pop();
            }

            if (abs(x - y) > 0) {
                pq.push(abs(x - y));
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};