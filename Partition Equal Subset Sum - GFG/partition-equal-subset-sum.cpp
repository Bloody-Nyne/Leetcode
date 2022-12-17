//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[]){
        int sum = getSum(arr,n);
        if(sum%2 != 0) return false;
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        return slave(n-1,sum/2,arr,dp);
    }
private:

    bool slave(int ind,int target,int nums[],vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == 0) return nums[0] == target;
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notTaken = slave(ind-1,target,nums,dp);
        int taken = false;
        if(nums[ind] <= target)
            taken = slave(ind-1,target-nums[ind],nums,dp);
        
        return dp[ind][target] = taken || notTaken;
    }

    int getSum(int arr[],int n){
        int sum = 0;
        for(int i=0;i<n;i++) sum += arr[i];
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends