class Solution {
public:
    //Memoization
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
        //tabulation
        vector<int> prev(amount+1,0),cur(amount+1,0);
        for(int t=0;t<=amount;t++) {
            if(t % coins[0] == 0) prev[t] = t/coins[0];
            else prev[t] = 1e9;
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                int notTake = 0 + prev[t];
                int take = 1e9;
                if(coins[i] <= t) 
                    take = 1 + cur[t-coins[i]];
                cur[t] = min(take,notTake);
            }
            prev = cur;
        }
        int ans = prev[amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};