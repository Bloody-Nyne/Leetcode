//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    int mod = 1e9+7;
    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<vector<ll>> pascal(n+1);
        for(int i=0;i<=n;i++){
            pascal[i].resize(i+1);
            pascal[i][0] = pascal[i][i] = 1;
            for(int j=1;j<i;j++){
                pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j])%mod;
            }
        }
        vector<ll> ans = pascal[n-1];
        return ans;
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends