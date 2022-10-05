class Solution {
public:
    int solve(int i,int j,string &s,string &t,vector<vector<int>>& dp){
        if(i == 0) return j;
        if(j == 0) return i;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i-1] == t[j-1])
            return  dp[i][j] = solve(i-1,j-1,s,t,dp);
        else{
            return dp[i][j] = min( 1 + solve(i,j-1,s,t,dp),min(
             1 + solve(i-1,j,s,t,dp),
             1 + solve(i-1,j-1,s,t,dp)));
        }
    }
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++) dp[0][j] = j;
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = min( 1 + dp[i][j-1],min(1 + dp[i-1][j],1 + dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};