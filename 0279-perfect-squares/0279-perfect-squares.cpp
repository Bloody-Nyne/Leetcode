class Solution {
public:
    int solve(int ind,vector<int>& dp){
        if(ind == 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int mini = 1e9;
        for(int i=1;i*i<=ind;i++){
            int minValue = 1 + solve(ind-i*i,dp);
            mini = min(mini,minValue);
        }
        return dp[ind] = mini;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 0;
        
        for(int num=1;num<=n;num++){
            int mini = 1e9;
            for(int i=1;i*i<=num;i++){
                int minValue = 1 + dp[num-i*i];
                mini = min(mini,minValue);
            }
            dp[num] = mini;
        }
        return dp[n];
    }
};