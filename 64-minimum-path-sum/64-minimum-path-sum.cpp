class Solution {
private:
    long long int solve(int n,int m,vector<vector<int>>& grid,vector<vector<long long int>>& dp){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 && j == 0) dp[0][0] = grid[0][0];
                else{
                    int up=INT_MAX,left=INT_MAX;
                    if(i > 0) up = grid[i][j] + dp[i-1][j];
                    if(j > 0) left = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long int>> dp(n,vector<long long int>(m,-1));
        
        return solve(n,m,grid,dp);
    }
};