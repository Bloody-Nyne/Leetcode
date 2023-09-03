class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        //return gridPaths(m-1,n-1,m,n,dp);
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(row == 0 && col == 0) dp[0][0] = 1;
                else{
                    int up=0,left=0;
                    if(row > 0) up = dp[row-1][col];
                    if(col > 0) left = dp[row][col-1];
                    dp[row][col] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
private:
    int gridPaths(int row,int col,int m,int n,vector<vector<int>>& dp){
        if(row == 0 && col == 0) return 1;
        if(row < 0 || row >= m || col < 0 || col >= n) return 0;

        if(dp[row][col] != -1) return dp[row][col];

        int up = gridPaths(row-1,col,m,n,dp);
        int left = gridPaths(row,col-1,m,n,dp);

        return dp[row][col] = up+left;
    }
};