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
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //return slave(n-1,m-1,pattern,str,dp);
        dp[0][0] = 1;
        for(int j=1;j<=m;j++) dp[0][j] = 0;
        for(int i=1;i<=n;i++) {
            dp[i][0] = allstar(pattern,i);
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(pattern[i-1] == str[j-1] || pattern[i-1] == '?') 
                    dp[i][j] = dp[i-1][j-1];
                else if(pattern[i-1] == '*') 
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else 
                    dp[i][j] = false;
            }
        }
        
        return dp[n][m];
    }
  private:
    int slave(int i,int j,string pattern,string str,vector<vector<int>>& dp){
        if (i < 0 && j < 0)
            return true; // both string get finished.
        if (i < 0 && j >= 0)
            return false; //pattern string got finished first
        if (j < 0 && i >= 0)
            return allstar(pattern, i);//str string finished first so check if pattern has all stars or not.
            
        if(dp[i][j] != -1) return dp[i][j];
        
        if(pattern[i] == str[j] || pattern[i] == '?') return dp[i][j] = slave(i-1,j-1,pattern,str,dp);
        else if(pattern[i] == '*') return dp[i][j] = slave(i-1,j,pattern,str,dp) || slave(i,j-1,pattern,str,dp);
        else return dp[i][j] = false;
        
    }
    bool allstar(string str,int n){
        for(int i=1;i<=n;i++){
            if(str[i-1] != '*') return false;
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