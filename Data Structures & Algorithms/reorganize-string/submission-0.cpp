class Solution {
public:
    string reorganizeString(string s) {

        string ans = "";

        map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        queue<pair<int, pair<int, char>>> q;

        for (char ch : s) {
            mp[ch]++;
        }

        for (auto m : mp) {
            pq.push({m.second, m.first});
        }

        int idx = 0;

        bool is_possible = true;
        while (idx < s.length()) {

            if (!q.empty() && q.front().second.first == idx) {
                pq.push({q.front().first, q.front().second.second});
                q.pop();
            }

            if (pq.empty()) {
                return "";
            }

            if (!pq.empty()) {
                auto p = pq.top();
                pq.pop();
                char ch = p.second;
                int val = p.first;
                ans += ch;

                if (val - 1 > 0) {
                    q.push({val - 1, {idx + 2, ch}});
                }
            }

            idx++;
        }

        return ans;
    }
};