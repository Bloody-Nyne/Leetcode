//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    set<char> st;
    int i=0,j=0,ans=0;
    while(j < S.length()){
        if(st.count(S[j])){
            st.erase(S[i]);
            i++;
        }
        else{
            st.insert(S[j]);
            j++;
            ans = max(ans,(int)st.size());
        }
    }
    return ans;
}