//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int mod = 1e9+7;
	int distinctSubsequences(string str)
    {
        int n=str.length();
        vector<int>dp(n+1);
        dp[0]=1;
        unordered_map<char,int>map;
        for(int i=1;i<=n;i++)
        {
            char ch=str[i-1];
            dp[i]=(2*dp[i-1])%mod;
            if(map.find(ch)!=map.end())
            {
                int index=map[ch];
                dp[i]=(dp[i]-dp[index-1]+mod)%mod;
                
            }
            map[ch]=i;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends