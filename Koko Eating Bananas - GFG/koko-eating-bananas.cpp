//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int Solve(int N, vector<int>& piles, int H) {
        int left = 1;
        int right = 0;
        for(int i=0;i<N;i++){
            right = max(right,piles[i]);
        }
        int ans = right;
        while(left <= right){
            int k = left + (right-left)/2;
            long int hrs = 0;
            for(int i=0;i<N;i++){
                hrs += ceil((double)piles[i]/k);
            }
            if(hrs <= H){
                ans = min(ans,k);
                right = k - 1;
            }
            else
                left = k + 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends