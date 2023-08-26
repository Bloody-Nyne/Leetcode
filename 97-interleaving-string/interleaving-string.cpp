class Solution {
public:
    bool solve(int i,int j,int k,string s1,string s2,string s3,vector<vector<int>>& dp){
        if(i <= 0 && j <= 0 && k <= 0) return true;
        
        if(dp[i][j] != -1) return dp[i][j];

        if(i > 0 && s1[i-1] == s3[k-1] && j > 0 && s2[j-1] == s3[k-1])
            return dp[i][j] = (solve(i-1,j,k-1,s1,s2,s3,dp) || solve(i,j-1,k-1,s1,s2,s3,dp));
        else if(i > 0 && s1[i-1] == s3[k-1]) 
            return dp[i][j] = solve(i-1,j,k-1,s1,s2,s3,dp);
        else if(j > 0 && s2[j-1] == s3[k-1])
            return dp[i][j] = solve(i,j-1,k-1,s1,s2,s3,dp);
        else
            return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(),m = s2.size();
        if((n+m) != s3.length()) return false;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,s3.length(),s1,s2,s3,dp);
    }
};