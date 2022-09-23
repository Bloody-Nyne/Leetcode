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
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,obstacleGrid,dp);
    }
};