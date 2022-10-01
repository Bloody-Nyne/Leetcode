class Solution {
public:
    int solve(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(ind == 0){
            if(target%nums[0] == 0) return 1;
            return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notTake = solve(ind-1,target,nums,dp);
        int take = 0;
        if(nums[ind] <= target) take = solve(ind,target-nums[ind],nums,dp);
        
        return dp[ind][target] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int t=0;t<=amount;t++){
            if(t%coins[0] == 0) dp[0][t] = 1;
            else dp[0][t] = 0;
        }
        for(int ind=1;ind<n;ind++){
            for(int t=0;t<=amount;t++){
                int notTake = dp[ind-1][t];
                int take = 0;
                if(coins[ind] <= t) take = dp[ind][t-coins[ind]];
                dp[ind][t] = take + notTake;
            }
        }
        int ans = 0;
        ans = dp[n-1][amount];
        return ans;
    }
};