//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        solve(n,0,0,"",ans);
        return ans;
    }
    void solve(int n,int open,int close,string str,vector<string>& ans){
        if(open == n && close == n){
            ans.push_back(str);
            return;
        }
        if(open < n) {
            solve(n,open+1,close,str+"(",ans);
        }
        if(close < open){
            solve(n,open,close+1,str+")",ans);
        }
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends