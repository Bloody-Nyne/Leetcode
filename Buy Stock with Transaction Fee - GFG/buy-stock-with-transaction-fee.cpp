//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return slave(0,true,fee,prices,dp);
    }
    private:
    long long slave(int ind,bool buy,int fee,vector<long long>& prices,vector<vector<int>>& dp){
        if(ind == prices.size()) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
       long long notTake = -1e9;
       long long take = -1e9;
       if(buy){
           notTake = 0 + slave(ind+1,true,fee,prices,dp);//not buy stock
           take = -prices[ind] + slave(ind+1,false,fee,prices,dp); // buy the stock
       }
       else{
           notTake = 0 + slave(ind+1,false,fee,prices,dp);//not sell the stock
           take = prices[ind] - fee + slave(ind+1,true,fee,prices,dp);//sell the stock
       }
       return dp[ind][buy] = max(take,notTake);
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends