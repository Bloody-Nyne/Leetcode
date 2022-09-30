class Solution {
public:
    int count(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(ind == 0) {
            if(target%nums[0] == 0) return target/nums[0];
            return 1e9;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notTake = 0 + count(ind-1,target,nums,dp);
        int take = 1e9;
        if(nums[ind] <= target) take = 1 + count(ind,target-nums[ind],nums,dp);
        
        return dp[ind][target] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = count(n-1,amount,coins,dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};