class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int, char>> pq;

        int actual_length = a + b + c;
        string ans = "";

        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});
        int idx = 0;

        while (!pq.empty() && idx < actual_length) {

            auto p = pq.top();
            pq.pop();

            int val = p.first;
            int ch = p.second;

            if (idx - 1 >= 0 && idx - 2 >= 0 && ans[idx - 1] == ans[idx - 2] &&
                ch == ans[idx - 1]) {

                if (!pq.empty()) {

                    auto p1 = pq.top();
                    ans += p1.second;
                    pq.pop();
                    pq.push(p);
                    if (p1.first - 1 > 0)
                        pq.push({p1.first - 1, p1.second});

                } else {
                    break;
                }

            } else {
                ans += ch;
                if (val - 1 > 0)
                    pq.push({val - 1, ch});
            }
            idx++;
        }

        return ans;
    }
};