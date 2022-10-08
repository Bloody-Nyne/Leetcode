class Solution {
public:
    int solve(int ind,int buy,int cap,vector<int>& nums,vector<vector<vector<int>>>& dp){
        if(cap == 0) return 0;
        if(ind == nums.size()) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        
        int profit = -1e9;
        if(buy){
            profit = max(-nums[ind] + solve(ind+1,0,cap,nums,dp), solve(ind+1,1,cap,nums,dp));
        }
        else{
            profit = max(nums[ind] + solve(ind+1,1,cap-1,nums,dp), solve(ind+1,0,cap,nums,dp));
        }
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,dp); // ind,buy,cap,arr
    }
};