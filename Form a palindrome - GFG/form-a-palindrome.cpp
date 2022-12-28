//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string s){
        string t = s;
        reverse(t.begin(),t.end());
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int len =  slave(n-1,n-1,s,t,dp);
        return n - len;
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
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends