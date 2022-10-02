class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int ind,int k,int target,vector<vector<int>>& dp){
        if(ind == 1) return target <= k;
        if(dp[ind][target] != -1) return dp[ind][target];
        
        dp[ind][target] = 0;
        int count = 0;
        for(int face=1;face<=k;face++){
            if(target-face > 0) count = (count + solve(ind-1,k,target-face,dp))%mod;
        }
        
        return dp[ind][target] = count;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0] = 1;

        for(int ind=1;ind<=n;ind++){
            for(int sum=1;sum<=target;sum++){
                for(int face=1;face<=k;face++){
                    if(sum - face >= 0)
                        dp[ind][sum] = (dp[ind][sum] + dp[ind-1][sum-face])%mod;
                }
            }
        }
        return dp[n][target];
    }
};