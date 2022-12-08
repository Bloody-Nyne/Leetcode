//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n,-1);
        return solve(n-1,k,height,dp);
    }
private:
    int solve(int ind,int k,vector<int>& height,vector<int>& dp){
        if(ind == 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int jump = 1e9;
        for(int i=1;i<=k;i++){
            if(ind-i >= 0){
                int profit = abs(height[ind] - height[ind-i]) + solve(ind-i,k,height,dp);
                jump = min(jump,profit);   
            }
        }
        return dp[ind] = jump;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends