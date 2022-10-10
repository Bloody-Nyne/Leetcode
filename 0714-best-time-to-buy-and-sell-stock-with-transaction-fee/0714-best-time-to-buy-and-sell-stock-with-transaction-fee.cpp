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
        vector<int> ahead(2,0),cur(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    cur[buy] = max(-prices[ind] + ahead[0], ahead[1]);
                }
                else{
                    cur[buy] = max(prices[ind] - fee + ahead[1], ahead[0]);
                }
            }
            ahead = cur;
        }
        return ahead[1];
    }
};