class Solution {
public:
    int solve(int ind,vector<int>& nums,vector<int>& dp){
        if(ind < 0) return 0;
        if(ind == 1 || ind == 0) return nums[ind];
        if(dp[ind] != -1) return dp[ind];
        
        int one = solve(ind-1,nums,dp);
        int two = solve(ind-2,nums,dp);
        
        return dp[ind] = nums[ind] + min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(n-1,cost,dp), solve(n-2,cost,dp));
    }
};