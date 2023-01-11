//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return slave(0,-1,a,n,dp);
    }
    private:
    int slave(int ind,int p_ind,int a[],int n,vector<vector<int>>& dp){
        if(ind == n)
            return 0;
            
        if(dp[ind][p_ind+1] != -1) 
            return dp[ind][p_ind+1];
        
        int notTake = 0 + slave(ind+1,p_ind,a,n,dp);
        int take = 0;
        if(p_ind == -1 || a[ind] > a[p_ind]){
            take = 1 + slave(ind+1,ind,a,n,dp);
        }
        return dp[ind][p_ind+1] = max(take,notTake);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends