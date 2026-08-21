#include<cstring>
class Solution {

private:
    int t[(int)1e4+1];
    int solve(vector<int>& c, int n) {
        if(n < 0) return INT_MAX;
        if(n==0) return 0;
        if(t[n]!=-1) return t[n];


        int result = INT_MAX;
        for (int i = 0; i < c.size(); i++) {

         int ans= solve(c ,n-c[i]);
         if(ans==INT_MAX) continue;
         result = min(result , ans+1);

        }

        return t[n]=result ;
    }    
public:
   
    int coinChange(vector<int>& coins, int amount) {
        memset(t,-1,sizeof(t));
        int ans=solve(coins,amount);

       return ans==INT_MAX ? -1 : ans;
        
    }
};
