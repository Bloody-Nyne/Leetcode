//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0;i<n;i++) sum += arr[i];
	    vector<vector<int>> dp(n,vector<int>(sum+1,0));
	    bool dummy = isSubsetSum(arr,sum,dp,n);
	    int mini = 1e9;
	    
	    for(int i=0;i<=sum;i++){
	        if(dp[n-1][i] == true){
	            int diff = abs(i - (sum - i));
	            mini = min(mini,diff);
	        }
	    }
	    return mini;
	} 
	
private:
    bool isSubsetSum(int nums[], int sum, vector<vector<int>>& dp,int n){
        for(int i=0;i<n;i++) dp[i][0] = 1;
        for(int j=0;j<=sum;j++) dp[0][j] = nums[0] == j;
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=sum;target++){
                int notTaken = dp[ind-1][target];
                int taken = false;
                if(nums[ind] <= target)
                    taken = dp[ind-1][target-nums[ind]];
                
                dp[ind][target] = taken || notTaken;
            }
        }
        return dp[n-1][sum];
    }
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends