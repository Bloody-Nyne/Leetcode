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
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = 0;i<n;i++) dp[n-1][i] = triangle[n-1][i];
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                int down = INT_MAX,diag = INT_MAX;
                down = triangle[i][j] + dp[i+1][j];
                diag = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,diag);
            }
        }
        return dp[0][0];
    }
};