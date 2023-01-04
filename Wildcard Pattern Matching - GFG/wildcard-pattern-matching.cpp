//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str){
        int n = pattern.length();
        int m = str.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return slave(n-1,m-1,pattern,str,dp);
    }
  private:
    int slave(int i,int j,string pattern,string str,vector<vector<int>>& dp){
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (j < 0 && i >= 0)
            return allstar(pattern, i);
            
        if(dp[i][j] != -1) return dp[i][j];
        
        if(pattern[i] == str[j] || pattern[i] == '?') return dp[i][j] = slave(i-1,j-1,pattern,str,dp);
        else if(pattern[i] == '*') return dp[i][j] = slave(i-1,j,pattern,str,dp) || slave(i,j-1,pattern,str,dp);
        else return dp[i][j] = false;
        
    }
    bool allstar(string str,int n){
        for(int i=0;i<=n;i++){
            if(str[i] != '*') return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends