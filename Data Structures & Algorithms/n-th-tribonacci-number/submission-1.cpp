#include<cstring>
class Solution {
private:
    int t[38];
    int solve(int n) {
        if (n < 3) {
            return t[n];
        }
        if(t[n]!=-1) return t[n];

        return t[n] = solve(n - 1) + solve(n - 2) + solve(n - 3);
    }

public:
    int tribonacci(int n) {
        memset(t, -1, sizeof(t));
        t[0] = 0;
        t[1] = 1;
        t[2] = 1;
        return solve(n);
    }
};