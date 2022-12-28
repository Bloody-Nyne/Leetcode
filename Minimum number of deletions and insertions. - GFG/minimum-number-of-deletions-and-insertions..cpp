//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
	int minOperations(string str1, string str2) 
	{ 
	    int n = str1.length();
	    int m = str2.length();
	    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
	    int lenOfLCS = slave(n-1,m-1,str1,str2,dp);
	    return n+m-2*lenOfLCS; //(n-lenOfLCS) + (m-lenOfLCS);
	} 
private:
    int slave(int ind1,int ind2,string s,string t,vector<vector<int>>& dp){
        if(ind1 < 0 || ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(s[ind1] == t[ind2])
            return dp[ind1][ind2] = 1 + slave(ind1-1,ind2-1,s,t,dp);
        else
            return dp[ind1][ind2] = max(slave(ind1-1,ind2,s,t,dp), slave(ind1,ind2-1,s,t,dp));
    }
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends