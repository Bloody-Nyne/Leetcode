//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	static bool comp(int a,int b){
	    return a > b;
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M,vector<int>(V+1,-1));
	    int ans = slave(M-1,V,coins,dp);
	    if(ans >= 1e9) return -1;
	    return ans;
	} 
	int slave(int ind,int W,int coins[],vector<vector<int>>& dp){
	    if(ind == 0){
	        if(W%coins[0] == 0) return W/coins[0];
	        else return 1e9;
	    }
	    
	    if(dp[ind][W] != -1) return dp[ind][W];
	    
	    int notTake = 0 + slave(ind-1,W,coins,dp);
	    int take = 1e9;
	    if(coins[ind] <= W){
	        take = 1 + slave(ind,W-coins[ind],coins,dp);
	    }
	    return dp[ind][W] = min(take,notTake);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends