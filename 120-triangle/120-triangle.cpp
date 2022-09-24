class Solution {
private:
    int solve(vector<vector<int>>& arr,int row,int col,vector<vector<int>>& dp){
        int n = arr.size();
        if(row == n-1) return arr[n-1][col];
        if(dp[row][col] != -1) return dp[row][col];
        int down = arr[row][col] + solve(arr,row+1,col,dp);
        int diag = arr[row][col] + solve(arr,row+1,col+1,dp);
        
        return dp[row][col] = min(down,diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(triangle,0,0,dp);
    }
};