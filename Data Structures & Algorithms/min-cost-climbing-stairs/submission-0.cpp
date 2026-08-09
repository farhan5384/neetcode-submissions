#include<cstring>
class Solution {

private:
 int t[1001];
 int solve(vector<int>&cost,int n){
     if(n>= cost.size()){
         return 0;
     }
     if(t[n]!=-1){
        return t[n];
     }


     int a1= solve(cost,n+1);
     int a2= solve(cost, n+2);
    return t[n]=  cost[n]+min(a1,a2);
 }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // ekta dummy  note nile moja hoto
    memset(t,-1,sizeof(t));
   return min(solve(cost,0),solve(cost,1));
        
    }
};