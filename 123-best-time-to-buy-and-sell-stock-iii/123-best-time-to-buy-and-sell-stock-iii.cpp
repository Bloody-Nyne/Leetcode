class Solution {
public:
    int solve(int ind,int buy,int cap,vector<int>& nums,vector<vector<vector<int>>>& dp){
        if(cap == 0 || ind == nums.size()) return 0;
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
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
       // return solve(0,1,2,prices,dp); // ind,buy,cap,arr
        
        for(int ind=0;ind<n;ind++){
            for(int buy=0;buy<=1;buy++){
                dp[ind][buy][0] = 0;
            }
        }
        for(int buy=1;buy<=1;buy++){
            for(int cap=0;cap<3;cap++){
                dp[n][buy][cap] = 0;
            }
        }
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<3;cap++){
                    int profit = -1e9;
                    if(buy){
                        profit = max(-prices[ind] + dp[ind+1][0][cap],dp[ind+1][1][cap]);
                    }
                    else{
                        profit = max(prices[ind] + dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};