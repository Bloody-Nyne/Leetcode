//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int w, int profit[], int weight[])
    {
        vector<vector<int>> dp(n,vector<int>(w+1,0));
       // return slave(n-1,w,profit,weight,dp);
        for(int j=0;j<=w;j++){
            dp[0][j] = (j/weight[0])*profit[0];
        }
        for(int ind=1;ind<n;ind++){
            for(int W=0;W<=w;W++){
                int notTaken = 0 + dp[ind-1][W];
                int taken = -1e9;
                if(weight[ind] <= W)
                    taken = profit[ind] + dp[ind][W-weight[ind]];
    
                dp[ind][W] = max(taken,notTaken);
            }
        }
        return dp[n-1][w];
    }
private:
    int slave(int ind,int W,vector<int>& profit,vector<int>& weight,vector<vector<int>>& dp){
        if(ind == 0){
            return (W/weight[0]) * profit[0];
        }
        
        if(dp[ind][W] != -1) return dp[ind][W];
        
        int notTaken = 0 + slave(ind-1,W,profit,weight,dp);
        int taken = -1e9;
        if(weight[ind] <= W)
            taken = profit[ind] + slave(ind,W-weight[ind],profit,weight,dp);
        
        return dp[ind][W] = max(taken,notTaken);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends