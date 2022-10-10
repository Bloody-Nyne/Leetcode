class Solution {
public:
    int solve(int ind,int buy,int fee,vector<int>& prices,vector<vector<int>>& dp){
        if(ind == prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy){
            return dp[ind][buy] = max(-prices[ind] + solve(ind+1,0,fee,prices,dp), solve(ind+1,1,fee,prices,dp));
        }
        return dp[ind][buy] = max(prices[ind] - fee + solve(ind+1,1,fee,prices,dp), solve(ind+1,0,fee,prices,dp));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,fee,prices,dp);
    }
};