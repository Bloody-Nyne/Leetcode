//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        vector<vector<int>> dp(n,vector<int>(n,0));
        //return memo(0,0,triangle,dp);
        for(int j=0;j<n;j++) dp[n-1][j] = triangle[n-1][j];
        for(int row=n-2;row>=0;row--){
            for(int col=0;col<row+1;col++){
                int down = triangle[row][col] + dp[row+1][col];
                int diag = triangle[row][col] + dp[row+1][col+1];
                dp[row][col] = min(down,diag);
            }
        }
        return dp[0][0];
    }
    private:
    int memo(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(row == grid.size() - 1) return grid[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        
        int down = grid[row][col] + memo(row+1,col,grid,dp);
        int diag = grid[row][col] + memo(row+1,col+1,grid,dp);
        
        return dp[row][col] = min(down,diag);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends