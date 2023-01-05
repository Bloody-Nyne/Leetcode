//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        //return slave(0,true,fee,prices,dp);
        dp[n][0] = dp[n][1] = 0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
               long long notTake = -1e9;
               long long take = -1e9;
               if(buy){
                   notTake = 0 +dp[ind+1][true];//not buy stock
                   take = -prices[ind] + dp[ind+1][false]; // buy the stock
               }
               else{
                   notTake = 0 + dp[ind+1][false];//not sell the stock
                   take = prices[ind] - fee + dp[ind+1][true];//sell the stock
               }
               dp[ind][buy] = max(take,notTake);
            }
        }
        return dp[0][1];
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