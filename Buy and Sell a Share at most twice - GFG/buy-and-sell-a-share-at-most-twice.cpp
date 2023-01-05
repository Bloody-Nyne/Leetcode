//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int slave(int ind,int buy,int limit,vector<int>& price,vector<vector<vector<int>>>& dp){
    if(ind == price.size() || limit == 0) return 0; 
    
    if(dp[ind][buy][limit] != -1) return dp[ind][buy][limit];
    
    int take = -1e9;
    int notTake = -1e9;
    if(buy){
        notTake = 0 + slave(ind+1,true,limit,price,dp);
        take = -price[ind] + slave(ind+1,false,limit,price,dp);
    }
    else{
        notTake = 0 + slave(ind+1,false,limit,price,dp);
        take = price[ind] + slave(ind+1,true,limit-1,price,dp);
    }
    return dp[ind][buy][limit] = max(notTake,take);
}

int maxProfit(vector<int>&price){
    int n = price.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    //return slave(0,true,2,price,dp);
    dp[n][0][0] = dp[n][1][0] = 0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<2;buy++){
            for(int limit=1;limit<3;limit++){
                int take = -1e9;
                int notTake = -1e9;
                if(buy){
                    notTake = 0 + dp[ind+1][true][limit];
                    take = -price[ind] + dp[ind+1][false][limit];
                }
                else{
                    notTake = 0 + dp[ind+1][false][limit];
                    take = price[ind] + dp[ind+1][true][limit-1];
                }
                dp[ind][buy][limit] = max(notTake,take);
            }
        }
    }
    return dp[0][1][2];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends