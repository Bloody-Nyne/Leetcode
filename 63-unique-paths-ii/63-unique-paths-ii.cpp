class Solution {
private:
    int solve(int row,int col,vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row >= 0 && col >= 0 && grid[row][col] == 1) return 0;
        if(row == 0 && col == 0) return 1;
        if(row < 0 || col < 0) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        int up = solve(row-1,col,grid,dp);
        int left = solve(row,col-1,grid,dp);
        
        return dp[row][col] = up + left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(obstacleGrid[row][col] == 1) dp[row][col] = 0;
                else if(row == 0 && col == 0) dp[row][col] = 1;
                else{
                    int up = 0,left = 0;
                    if(row > 0) up = dp[row-1][col];
                    if(col > 0) left = dp[row][col-1];
                    dp[row][col] = up + left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};