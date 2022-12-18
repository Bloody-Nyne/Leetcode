//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9+7;
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = 0;
        for(auto it: arr) sum += it;
        if(sum < d) return 0;
        if((sum - d) % 2) return 0;
        int target = (sum - d)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return slave(n-1,target,arr,dp);
    }
private:
    int slave(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
	    if(ind == 0)
         {
            if(target==0 and nums[0]==0) return 2;
            if(target==0 or target==nums[0]) return 1;
            return 0;
        }
	    if(dp[ind][target] != -1) return dp[ind][target];
	    
	    int notTaken = (slave(ind-1,target,nums,dp))%mod;
	    int taken = 0;
	    if(nums[ind] <= target)
	        taken = (slave(ind-1,target-nums[ind],nums,dp))%mod;
	        
        return dp[ind][target] = (taken + notTaken)%mod;
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends