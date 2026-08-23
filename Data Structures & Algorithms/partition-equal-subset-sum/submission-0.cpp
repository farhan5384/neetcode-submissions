#include<cstring>
class Solution {
private:
    int t[201][10001];
    bool solve(vector<int>& nums, int idx, int curr_sum, int target) {
        if (idx >= nums.size()) {
            return false;
        }
        if (curr_sum > target) {
            return false;
        }
        if (curr_sum == target) {
            return true;
        }
        if (t[idx][curr_sum] != -1)
            return t[idx][curr_sum];

        t[idx][curr_sum] = solve(nums, idx + 1, curr_sum, target);
        if (t[idx][curr_sum]==1)
            return t[idx][curr_sum];

        t[idx][curr_sum] = solve(nums, idx + 1, curr_sum + nums[idx], target);
        if (t[idx][curr_sum]==1)
            return t[idx][curr_sum];

        return t[idx][curr_sum] = false;
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        memset(t, -1, sizeof(t));
        if (sum % 2 != 0)
            return false;
        sum /= 2;
        return solve(nums, 0, 0, sum);
    }
};