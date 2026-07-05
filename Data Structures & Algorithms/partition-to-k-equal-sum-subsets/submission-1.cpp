class Solution {
private:
 bool backtrack(vector<int>&nums,vector<int> & vec ,int& target,int idx,int& k){
    if(idx== nums.size()) return true;

    for(int i=0 ; i<k;i++){
        if(vec[i]+nums[idx]<=target){
            vec[i]+=nums[idx];
            if(backtrack(nums,vec,target,idx+1,k)) return true;
            vec[i]-=nums[idx];
        }
        if(vec[i]==0) break;

    }

    return false;

 }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        vector<int> vec(k,0);

        int target = accumulate(nums.begin(),nums.end(),0);
        if(target%k!=0) return false;
        sort(nums.rbegin(),nums.rend());
        target/=k;
        
        return backtrack(nums,vec,target,0,k);

        
    }
};