//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,0);
       // return solve(n-1,height,dp);
        dp[0] = 0;
        for(int ind=1;ind<n;ind++){
            int jumpOne = abs(height[ind] - height[ind-1]) + dp[ind-1];
            int jumpTwo = 1e9;
            if(ind > 1)
                jumpTwo = abs(height[ind] - height[ind-2]) + dp[ind-2];
            
            dp[ind] = min(jumpOne,jumpTwo);
        }
        return dp[n-1];
    }
private:
    int solve(int ind,vector<int>& height,vector<int>& dp){
        if(ind == 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int jumpOne = abs(height[ind] - height[ind-1]) + solve(ind-1,height,dp);
        int jumpTwo = 1e9;
        if(ind > 1)
            jumpTwo = abs(height[ind] - height[ind-2]) + solve(ind-2,height,dp);
            
        return dp[ind] = min(jumpOne,jumpTwo);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends