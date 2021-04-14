// https://leetcode.com/problems/combination-sum-iv/
class Solution {
public:
    int fun(vector<int> nums,int target,vector<int> &dp){
        if(target <0)
            return 0;
        if(dp[target] != -1)
            return dp[target];
        if(target == 0)
            return 1;
        int count = 0;
        for(auto it : nums){
            if(it<=target){
                count += fun(nums,target-it,dp);
            }
            
            
        }
        dp[target] = count;
        return count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return fun(nums,target,dp);
    }
};