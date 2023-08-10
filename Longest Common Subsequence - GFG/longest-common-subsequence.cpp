//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solve(int i,int j,string s,string t,vector<vector<int>>& dp){
        if(i <= 0 || j <= 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i-1] == t[j-1]){
            return dp[i][j] = 1 + solve(i-1,j-1,s,t,dp);
        }
        else{
            return dp[i][j] = 0 + max(solve(i-1,j,s,t,dp), solve(i,j-1,s,t,dp));
        }
    }
    int lcs(int n, int m, string s, string t)
    {
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //return solve(n,m,s1,s2,dp);
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends