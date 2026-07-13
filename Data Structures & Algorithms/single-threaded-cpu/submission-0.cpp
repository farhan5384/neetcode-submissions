class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> sorted_task;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            p;

        vector<int> ans;

        for (int i = 0; i < tasks.size(); i++) {
            sorted_task.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(sorted_task.begin(), sorted_task.end());

     long long time = 0;
        int i = 0;
        int n = tasks.size();
        while (ans.size() < n) {

            while (i < n && sorted_task[i][0] <= time) {
                p.push({sorted_task[i][1], sorted_task[i][2]});
                i++;
            }

            if (!p.empty()) {

                auto& qw = p.top();
                int process = qw.first;
                int idx = qw.second;
                p.pop();
                ans.push_back(idx);

                time += process;
            }

            else {
                time = sorted_task[i][0];
            }
        }

        return ans;
    }
};