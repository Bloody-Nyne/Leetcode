//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return slave(n-1,m-1,s,t,dp);
    }
  private:
    int slave(int ind1,int ind2,string s,string t,vector<vector<int>>& dp){
        if(ind1 < 0) return ind2+1;
        if(ind2 < 0) return ind1+1;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(s[ind1] == t[ind2]) return dp[ind1][ind2] = 0 + slave(ind1-1,ind2-1,s,t,dp);
        else
            return dp[ind1][ind2] =  1 + min({slave(ind1,ind2-1,s,t,dp), slave(ind1-1,ind2,s,t,dp), slave(ind1-1,ind2-1,s,t,dp)});
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends