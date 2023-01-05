//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(2,vector<int>(K+1,-1)));
        return slave(0,true,K,A,N,dp);
    }
private:
    int slave(int ind,int buy,int limit,int prices[],int N,vector<vector<vector<int>>>& dp){
        if(ind == N || limit == 0) return 0;
        
        if(dp[ind][buy][limit] != -1) return dp[ind][buy][limit];
        
        int notTake = -1e9;
        int take = -1e9;
        if(buy){
            notTake = 0 + slave(ind+1,true,limit,prices,N,dp);
            take = -prices[ind] + slave(ind+1,false,limit,prices,N,dp);
        }
        else{
            notTake = 0 + slave(ind+1,false,limit,prices,N,dp);
            take = prices[ind] + slave(ind+1,true,limit-1,prices,N,dp);
        }
        return dp[ind][buy][limit] = max(notTake,take);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends