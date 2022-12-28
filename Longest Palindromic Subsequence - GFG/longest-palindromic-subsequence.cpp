//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return slave(n,m,s,t,dp);
    }
  private:
    int slave(int ind1,int ind2,string s,string t,vector<vector<int>>& dp){
        if(ind1 <= 0 || ind2 <= 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(s[ind1-1] == t[ind2-1])
            return dp[ind1][ind2] = 1 + slave(ind1-1,ind2-1,s,t,dp);
        else return dp[ind1][ind2] = max(slave(ind1-1,ind2,s,t,dp), slave(ind1,ind2-1,s,t,dp));
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends