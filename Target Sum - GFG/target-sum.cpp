//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&nums ,int x) {
        int n = nums.size();
        int totSum = 0;
        for(auto it: nums) totSum += it;
        if(totSum < x || (totSum-x)%2) return 0;
        int sum = (totSum - x)/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
       // return slave(n-1,sum,A,dp);
       for(int target=0;target<=sum;target++){
            if(target==0 && nums[0]==0) dp[0][target] = 2;
            else if(target==0 || target == nums[0]) dp[0][target] = 1;
            else dp[0][target] = 0;
       }
       for(int ind=1;ind<n;ind++){
           for(int target=0;target<=sum;target++){
                int notTaken = dp[ind-1][target];
                int taken = 0;
                if(nums[ind] <= target)
                    taken = dp[ind-1][target-nums[ind]];
                    
                dp[ind][target] = taken + notTaken;
           }
       }
       return dp[n-1][sum];
    }
private:
    int slave(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(ind == 0){
            if(target==0 && nums[0]==0)
                return 2;
            if(target==0 || target == nums[0])
                return 1;
            return 0;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notTaken = slave(ind-1,target,nums,dp);
        int taken = 0;
        if(nums[ind] <= target)
            taken = slave(ind-1,target-nums[ind],nums,dp);
            
        return dp[ind][target] = taken + notTaken;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends