class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[0][i] = matrix[0][i];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int ld=1e9,rd=1e9;
                if(j > 0 && i > 0) ld = matrix[i][j] + dp[i-1][j-1];
                int up = matrix[i][j] + dp[i-1][j];
                if(j < n-1) rd = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = min(ld,min(up,rd));
            }
        }
        int ans = dp[n-1][0];
        for(int j=0;j<n;j++) ans = min(ans,dp[n-1][j]);
        return ans;
    }
};