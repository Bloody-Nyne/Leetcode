//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> st;
        //vector<int> dp(s.size()+1,0);
        for(auto it: wordDict){
            st.insert(it);
        }
        int n = s.size();
        vector<bool> dp(n+1);
        dp[n]=1;
        for(int i=n-1;i>=0;i--) {
            string sub;
            for(int j=i;j<n;j++){
                sub += s[j];
                if (dp[i] = st.count(sub) && dp[j+1])
                    break;
            }
        }
        return dp[0];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends