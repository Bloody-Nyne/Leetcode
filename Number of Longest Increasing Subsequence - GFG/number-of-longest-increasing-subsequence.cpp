//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&arr) {
        vector<int> dp(n,1),cnt(n,1);
        int maxi = -1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[prev] < arr[i] && 1+dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if(arr[prev] < arr[i] && 1+dp[prev] == dp[i]){
                    cnt[i] += cnt[prev];
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == maxi) count += cnt[i];
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends