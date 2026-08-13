#include<cstring>
class Solution {
private:
    int  t[2][101];
    int solve(vector<int>& nums, int i ,int end ) {

        
        if (i >= end) {
            return 0;
        }

        if(t[end-nums.size()+1][i]!=-1){
            return t[end-nums.size()+1][i];
        }

        int ans1 = nums[i] + solve(nums, i + 2,end);
        int ans2 = solve(nums, i + 1,end);
     
        return t[end-nums.size()+1][i]=max(ans1,ans2);
    }

public:
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        if(nums.size()==1) return nums[0];

        int  ans= solve(nums,0 , nums.size()-1);
        int ans2= solve(nums,1 , nums.size());

        return max(ans,ans2);
        


    }
};