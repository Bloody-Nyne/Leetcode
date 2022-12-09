//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> grid)
    {
     /*    
      int ans = -1e9;
      vector<vector<int>> dp(n,vector<int>(n,-1));
      for(int j=0;j<n;j++){
          int temp = memo(n-1,j,grid,dp);
          ans = max(ans,temp);
      }
      return ans; */
      vector<vector<int>> dp(n,vector<int>(n,0));
      for(int j=0;j<n;j++) dp[0][j] = grid[0][j];
      for(int row=1;row<n;row++){
          for(int col=0;col<n;col++){
              int down = grid[row][col] + dp[row-1][col];
              int diagL = col > 0 ? grid[row][col] + dp[row-1][col-1] : -1e9;
              int diagR = col < n-1 ? grid[row][col] + dp[row-1][col+1] : -1e9;
              dp[row][col] = max(down,max(diagL,diagR));
          }
      }
      int ans = -1e9;
      for(int j=0;j<n;j++){
          ans = max(ans,dp[n-1][j]);
      }
      return ans;
    }
private:
    int memo(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(col < 0 || col >= grid.size()) return -1e9;
        if(row == 0) return grid[0][col];
        if(dp[row][col] != -1) return dp[row][col];
        
        int down = grid[row][col] + memo(row-1,col,grid,dp);
        int diagL = grid[row][col] + memo(row-1,col-1,grid,dp);
        int diagR = grid[row][col] + memo(row-1,col+1,grid,dp);
        
        return dp[row][col] = max(down,max(diagL,diagR));
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends