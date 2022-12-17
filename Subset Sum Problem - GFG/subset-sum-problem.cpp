//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return slave(n-1,sum,arr,dp); 
    }
private:
    bool slave(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == 0) return nums[0] == target;
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notTaken = slave(ind-1,target,nums,dp);
        int taken = false;
        if(nums[ind] <= target)
            taken = slave(ind-1,target-nums[ind],nums,dp);
        
        return dp[ind][target] = taken || notTaken;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends