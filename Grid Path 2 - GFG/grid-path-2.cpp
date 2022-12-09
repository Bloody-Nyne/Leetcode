//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod = 1e9 + 7;
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        //return memo(n-1,m-1,grid,dp);
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(row == 0 && col == 0 && !grid[row][col]) {
                    dp[row][col] = 1;
                    continue;
                }
                if(grid[row][col]){
                    dp[row][col] = 0;
                    continue;
                }
                int up = row > 0 ? dp[row-1][col] : 0;
                int left = col> 0 ? dp[row][col-1] : 0;
                dp[row][col] = (up + left)%mod;
            }
        }
        return dp[n-1][m-1];
    }
    private:
    int memo(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(row < 0 || col < 0) return 0;
        if(row == 0 && col == 0 && !grid[row][col]) return 1;
        if(grid[row][col]) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        
        int up = memo(row-1,col,grid,dp);
        int left = memo(row,col-1,grid,dp);
        
        return dp[row][col] = (up + left)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends