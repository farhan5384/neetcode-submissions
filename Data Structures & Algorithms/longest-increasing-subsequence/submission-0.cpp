#include<cstring>
class Solution {
private:
    int t[2501][2502];
    int solve(vector<int>& nums, int idx, int parent) {

        if (idx >= nums.size()) {
            return 0;
        }
        if (t[idx][parent + 1] != -1)
            return t[idx][parent + 1];

        int take = 0;

        if (parent == -1 || nums[idx] > nums[parent]) {

            take = 1 + solve(nums, idx + 1, idx);
        }
        int not_take = solve(nums, idx + 1, parent);

        return t[idx][parent + 1] = max(take, not_take);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));

        return solve(nums, 0, -1);
    }
};