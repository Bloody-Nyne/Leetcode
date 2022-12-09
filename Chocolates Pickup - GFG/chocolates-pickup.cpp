//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return memo(0,0,grid[0].size()-1,grid,dp);
    }
private:
    int memo(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()) return -1e9;
        if(i == grid.size() - 1) {
            if(j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxi = -1e9;
        for(int di=-1;di<=1;di++){
            for(int dj=-1;dj<=1;dj++){
                if(j1 == j2){
                    int ans = grid[i][j1] + memo(i+1,j1+di,j2+dj,grid,dp);
                    maxi = max(maxi,ans);
                }
                else{
                    int ans = grid[i][j1] + grid[i][j2] + memo(i+1,j1+di,j2+dj,grid,dp);
                    maxi = max(maxi,ans);
                }
            }
        }
        return dp[i][j1][j2] = maxi;
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
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends