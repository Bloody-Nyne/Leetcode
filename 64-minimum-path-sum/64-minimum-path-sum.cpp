class Solution {
private:
    long long int solve(int row,int col,vector<vector<int>>& grid,vector<vector<long long int>>& dp){
        if(row == 0 && col == 0) return grid[row][col];
        if(row < 0 || col < 0) return INT_MAX;
        
        if(dp[row][col] != -1) return dp[row][col];
        long long int up = grid[row][col] + solve(row-1,col,grid,dp);
        long long int left = grid[row][col] + solve(row,col-1,grid,dp);
        
        return dp[row][col] = min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long int>> dp(n,vector<long long int>(m,-1));
        
        return solve(n-1,m-1,grid,dp);
    }
};