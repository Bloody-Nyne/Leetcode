//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> dp(a,vector<int>(b,0));
       // return memo(a-1,b-1,dp);
        dp[0][0] = 1;
        for(int row=0;row<a;row++){
            for(int col=0;col<b;col++){
                if(row == 0 && col == 0) continue;
                int up = row > 0 ? dp[row-1][col] : 0;
                int left = col > 0 ? dp[row][col-1] : 0;
                dp[row][col] = up + left;
            }
        }
        return dp[a-1][b-1];
    }
    private:
    int memo(int row,int col,vector<vector<int>>& dp){
        if(row == 0 && col == 0) return 1;
        if(row < 0 || col < 0) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        
        int up = memo(row-1,col,dp);
        int left = memo(row,col-1,dp);
        
        return dp[row][col] = up + left;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends