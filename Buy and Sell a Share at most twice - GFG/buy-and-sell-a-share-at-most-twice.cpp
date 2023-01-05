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
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return slave(0,true,2,price,dp);
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