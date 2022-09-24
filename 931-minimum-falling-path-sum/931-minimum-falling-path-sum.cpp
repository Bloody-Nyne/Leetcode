class Solution {
private:
    int solve(int i,int j,vector<vector<int>>& arr,vector<vector<int>>& dp){
        int n  = arr.size();
        if(i < 0 || j < 0 || i>=n || j>=n) return 1e9;
        if(i == 0) return arr[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int ld = arr[i][j] + solve(i-1,j-1,arr,dp);
        int d  = arr[i][j] + solve(i-1,j,arr,dp);
        int rd = arr[i][j] + solve(i-1,j+1,arr,dp);
        
        return dp[i][j] = min(ld,min(d,rd));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans = 1e9;
        for(int j=0;j<n;j++) {
            int mini = solve(n-1,j,matrix,dp);
            ans = min(ans,mini);
        }
        return ans;
    }
};