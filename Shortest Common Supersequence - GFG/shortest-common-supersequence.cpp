//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s, string t, int m, int n)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        //int len = slave(m-1,n-1,X,Y,dp);
        for(int i=0;i<m;i++) dp[i][0] = 0;
        for(int j=0;j<n;j++) dp[0][j] = 0;
        for(int ind1=1;ind1<=m;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(s[ind1-1] == t[ind2-1]) dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
        int len = dp[m][n];
        return m+n-len;
    }
    private:
    int slave(int ind1,int ind2,string s,string t,vector<vector<int>>& dp){
        if(ind1 < 0 || ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(s[ind1] == t[ind2]) return dp[ind1][ind2] = 1 + slave(ind1-1,ind2-1,s,t,dp);
        return dp[ind1][ind2] = max(slave(ind1-1,ind2,s,t,dp), slave(ind1,ind2-1,s,t,dp));
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends