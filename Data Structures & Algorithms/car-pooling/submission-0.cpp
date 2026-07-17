class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            start;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            end;

        for (int i = 0; i < trips.size(); i++) {
            start.push({trips[i][1], trips[i][0]});
            end.push({trips[i][2], trips[i][0]});
        }

        int passenger = 0;

        while (!start.empty()) {

            auto p = start.top();
            start.pop();

            int start = p.first;

            while (!end.empty() && end.top().first <= p.first) {
                passenger -= end.top().second;
                end.pop();
            }
            passenger+= p.second;

            if(passenger > capacity)  return false;
        }

        return true;
    }
};